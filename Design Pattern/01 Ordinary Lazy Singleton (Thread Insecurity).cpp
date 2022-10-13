/*
Summary of C++ Thread Safety Singleton Patterns
Posted by BuzzPHP on Fri, 30 Aug 2019 16:18:23 +0200

What is thread safety?
In parallel programs with shared data, thread-safe code ensures that all threads can execute normally and correctly through synchronization mechanism, without data contamination and other unexpected situations.

How to ensure thread safety?
Lock shared resources to ensure that each resource variable is occupied by at least one thread at any time.
Let threads also have resources, without sharing resources in the process. For example, using threadlocal can maintain a private local variable for each thread.
What is the singleton pattern?
Singleton pattern refers to guaranteeing that only one instance of a class can be generated throughout the life cycle of the system to ensure the uniqueness of the class.

Classification of Singleton Patterns
The singleton model can be divided into the lazy and the hungry. The difference between them is that the time of creating the instance is different.

Lazy man type: refers to the system running, the instance does not exist, only when the need to use the instance, will create and use the instance. (Thread safety should be considered in this way)
Hungry Chinese: refers to the system as soon as it runs, it initializes the creation of instances, when needed, it can be called directly. (Thread-safe in itself, no multithreading issues)
Singleton Class Characteristics
Constructors and destructors are private ly typed for the purpose of prohibiting external constructions and destructions
The copy constructor and assignment constructor is private ly typed to prohibit external copy and assignment and to ensure the uniqueness of instances.
Class has a static function to get instances, which can be accessed globally.*/
//01 Ordinary Lazy Singleton (Thread Insecurity)
/////////////////// Ordinary Lazy Implementation--Thread Insecurity//////////////////
#include <iostream> // std::cout
#include <mutex>    // std::mutex
#include <pthread.h> // pthread_create

class SingleInstance
{

public:
    // Getting singleton objects
    static SingleInstance *GetInstance();

    // Release the singleton and call it when the process exits
    static void deleteInstance();
    
    // Print singleton address
    void Print();

private:
    // Construct and analyze it as private, prohibit external structure and Deconstruction
    SingleInstance();
    ~SingleInstance();

    // Construct its copy construction and assignment into private functions, forbid external copy and assignment
    SingleInstance(const SingleInstance &signal);
    const SingleInstance &operator=(const SingleInstance &signal);

private:
    // Unique singleton object pointer
    static SingleInstance *m_SingleInstance;
};

//Initialize static member variables
SingleInstance *SingleInstance::m_SingleInstance = NULL;

SingleInstance* SingleInstance::GetInstance()
{

    if (m_SingleInstance == NULL)
    {
        m_SingleInstance = new (std::nothrow) SingleInstance;  // Threads are insecure without locking, and multiple instances are created when threads are concurrent
    }

    return m_SingleInstance;
}

void SingleInstance::deleteInstance()
{
    if (m_SingleInstance)
    {
        delete m_SingleInstance;
        m_SingleInstance = NULL;
    }
}

void SingleInstance::Print()
{
    std::cout << "My instance memory address is:" << this << std::endl;
}

SingleInstance::SingleInstance()
{
    std::cout << "Constructor" << std::endl;
}

SingleInstance::~SingleInstance()
{
    std::cout << "Destructive function" << std::endl;
}
/////////////////// Ordinary Lazy Implementation--Thread Insecurity//////////////////

// Thread function
void *PrintHello(void *threadid)
{
    // Main threads and sub-threads are separated, and they do not interfere with each other. At the same time, sub-threads end and the resources of sub-threads are automatically recovered.
    pthread_detach(pthread_self());

    // Mandatory type conversion of incoming parameters, from untyped pointer to integer pointer, and then read
    int tid = *((int *)threadid);

    std::cout << "Hi, I am a thread ID:[" << tid << "]" << std::endl;

    // Print instance address
    SingleInstance::GetInstance()->Print();

    pthread_exit(NULL);
    return 0;
}

#define NUM_THREADS 5// Number of Threads

int main(void)
{
    pthread_t threads[NUM_THREADS] = {0};
    int indexes[NUM_THREADS] = {0}; // Save the value of i with an array

    int ret = 0;
    int i = 0;

    std::cout << "main() : start ... " << std::endl;

    for (i = 0; i < NUM_THREADS; i++)
    {
        std::cout << "main() : Create threads:[" << i << "]" << std::endl;
        
        indexes[i] = i; //Save the value of i first
        
        // When passing in, you must cast to void* type, that is, untyped pointer
        ret = pthread_create(&threads[i], NULL, PrintHello, (void *)&(indexes[i]));
        if (ret)
        {
            std::cout << "Error:cannot create thread," << ret << std::endl;
            exit(-1);
        }
    }

    // Manual release of single instance resources
    SingleInstance::deleteInstance();
    std::cout << "main() : End! " << std::endl;
    
    return 0;
}
// The results of the single case operation of the ordinary lazy man type are as follows:
// From the running results, we can see that the single-case constructor creates two, memory addresses are 0x7f3c980008c0 and 0x7f3c900008c0 respectively, so the ordinary lazy-type single-case is only suitable for single process, not for multi-threading, because it is thread insecure.

