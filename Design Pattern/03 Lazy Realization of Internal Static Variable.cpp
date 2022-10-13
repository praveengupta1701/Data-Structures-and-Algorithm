
// Lazy Singleton of 03 Internal Static Variables (C++11 Thread Safety)
/////////////////// Lazy Realization of Internal Static Variables//////////////////

#include <iostream> // std::cout
#include <mutex>    // std::mutex
#include <pthread.h> // pthread_create

class Single
{

public:
    // Getting a single instance object
    static Single &GetInstance();
    
    // Print instance address
    void Print();

private:
    // Prohibiting External Constructions
    Single();

    // Prohibiting External Deconstruction
    ~Single();

    // Prohibit external replication constructs
    Single(const Single &signal);

    // Prohibit external assignment operations
    const Single &operator=(const Single &signal);
};

Single &Single::GetInstance()
{
    // Realization of Single Example by Local Static Characteristic
    static Single signal;
    return signal;
}

void Single::Print()
{
    std::cout << "My instance memory address is:" << this << std::endl;
}

Single::Single()
{
    std::cout << "Constructor" << std::endl;
}

Single::~Single()
{
    std::cout << "Destructive function" << std::endl;
}


// Thread function
void *PrintHello(void *threadid)
{
    // Main threads and sub-threads are separated, and they do not interfere with each other. At the same time, sub-threads end and the resources of sub-threads are automatically recovered.
    pthread_detach(pthread_self());

    // Mandatory type conversion of incoming parameters, from untyped pointer to integer pointer, and then read
    int tid = *((int *)threadid);

    std::cout << "Hi, I am a thread ID:[" << tid << "]" << std::endl;

    // Print instance address
    Single::GetInstance().Print();

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
    // Single::deleteInstance();
    std::cout << "main() : End! " << std::endl;
    
    return 0;
}
/*
/////////////////// Lazy Realization of Internal Static Variables//////////////////
// Running results of lazy singletons with internal static variables:
// - std=c++0x compiler uses the characteristics of C++11. In the way of static variables in C++11, it is thread-safe. Only one instance is created. The memory address is 0x6016e8. This method is highly recommended and the code is the least!

// [root@lincoding singleInstall]#g++  SingleInstance.cpp -o SingleInstance -lpthread -std=c++0x
*/