
// 04 Hungry Chinese singleton (thread safety itself)
////////////////////////// The Hungry Man Realizes/////////////////////
#include <iostream> // std::cout
#include <mutex>    // std::mutex
#include <pthread.h> // pthread_create

class Singleton
{
public:
    // Get a single instance
    static Singleton* GetInstance();

    // Release single instance and call when process exits
    static void deleteInstance();
    
    // Print instance address
    void Print();

private:
    // Construct and analyze it as private, prohibit external structure and Deconstruction
    Singleton();
    ~Singleton();

    // Construct its copy construction and assignment into private functions, forbid external copy and assignment
    Singleton(const Singleton &signal);
    const Singleton &operator=(const Singleton &signal);

private:
    // Unique single instance object pointer
    static Singleton *g_pSingleton;
};

// Instance creation is initialized as soon as the code runs, which is thread-safe in itself.
Singleton* Singleton::g_pSingleton = new (std::nothrow) Singleton;

Singleton* Singleton::GetInstance()
{
    return g_pSingleton;
}

void Singleton::deleteInstance()
{
    if (g_pSingleton)
    {
        delete g_pSingleton;
        g_pSingleton = NULL;
    }
}

void Singleton::Print()
{
    std::cout << "My instance memory address is:" << this << std::endl;
}

Singleton::Singleton()
{
    std::cout << "Constructor" << std::endl;
}

Singleton::~Singleton()
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
    Singleton::GetInstance()->Print();

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
    Singleton::deleteInstance();
    std::cout << "main() : End! " << std::endl;
    
    return 0;
}
////////////////////////// The Hungry Man Realizes/////////////////////
// Running results of Hungry Chinese singleton:
// From the result of running, we can see that hungry Chinese constructor is initialized at the beginning of the program, so it is thread-safe.


// Characteristics and Choices
// Lazy-man style is time-for-space, which is suitable for less visits; lazy-man singletons with internal static variables are recommended, and the amount of code is less.
// The hungry Chinese style is to exchange space for time, which is suitable for the situation of large number of visits or more threads.