// NOTES:
// 1. If we say unique_ptr is for unique ownership and shared_ptr is for shared ownership, then we can say that unique_ptr is for owning the resource and shared_ptr is for sharing the resource.
//   weak_ptr is for non-ownership smart pointer.
// 2. It actually reference to an object which is managed by shared_ptr
// 3. A weak_ptr is created as a copy of shared_ptr.
// 4. We have to convert weak_ptr to shared_ptr in oreder to use the managed object.
// 5. It is used to remove cyclic dependencies between shared_ptr objects.

/* #include <iostream>
#include <memory>
using namespace std;

int main()
{
    auto shared_ptr = make_shared<int>(10);
    std::weak_ptr<int> weak_ptr(shared_ptr);//refence count not incerse only refencing or copy
    cout << "weak_ptr.use_count() = " << weak_ptr.use_count() << endl;
    cout << "shared_ptr.use_count() = " << shared_ptr.use_count() << endl;
    cout << "weak_ptr.expired() = " << weak_ptr.expired() << endl;//0 means not expired

    if (auto shared_ptr2 = weak_ptr.lock())//refence count incerse
    {
        cout << "*shared_ptr2:" << *shared_ptr2 << endl;
        cout << "shared_ptr2.use_count= " << shared_ptr2.use_count() << endl;
    }
    else
    {
        cout << "shared_ptr2 is expired" << endl;
    }

    weak_ptr.reset();// not point
    if (auto shared_ptr2 = weak_ptr.lock())
    {
        cout << "*shared_ptr2:" << *shared_ptr2 << endl;
        cout << "shared_ptr2.use_count= " << shared_ptr2.use_count() << endl;
    }
    else
    {
        cout << "shared_ptr2 is expired !! don't get the resouce" << endl;
    }
} */

//Cyclic Dependencies

#include <iostream>
#include <memory>
using namespace std;

struct Son;
struct Daughter;

struct Mother
{
    ~Mother()
    {
        cout << "Mother is destroyed" << endl;
    }

    void setSon(const std::shared_ptr<Son>& son)
    {
        this->son = son;
        // this->son = son.lock();// if it is shared ptr


    }

    void setDaughter(const std::shared_ptr<Daughter>& daughter)
    {
        this->daughter = daughter;
    }

    // std::shared_ptr<Son> son; // Cyclic dependency, dtor won't be called
    // std::shared_ptr<Daughter> daughter; // Cyclic dependency, dtor won't be called

    std::weak_ptr<Son> son;
    std::weak_ptr<Daughter> daughter;
};

struct Son
{
    Son(std::shared_ptr<Mother> m) : mother(m) {}
    ~Son()
    {
        cout << "Son is destroyed/gone" << endl;
    }

    std::shared_ptr<Mother> mother;
};

struct Daughter
{
    Daughter(std::shared_ptr<Mother> m) : mother(m) {}
    ~Daughter()
    {
        cout << "Daughter is destroyed/gone" << endl;
    }

    std::shared_ptr<Mother> mother;
};

int main()
{
    auto mother = std::make_shared<Mother>();
    auto son = std::make_shared<Son>(mother);
    auto daughter = std::make_shared<Daughter>(mother);

    mother->setSon(son);
    mother->setDaughter(daughter);

    son.reset();
    daughter.reset();
    mother.reset();
}