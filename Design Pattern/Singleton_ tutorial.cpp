/*This pattern involves a single class which is responsible to create an object while 
making sure that only single object gets created. This class provides a way to access
 its only object which can be accessed directly without need to instantiate the object
 of the class.*/
//----------------------------------------------------------------------------------//
/*We're going to create a Singleton Object class. Singleton Object class have its 
constructor as private and have a static instance of itself.*/
//------------------------------------------------------------------------------------//
#include <iostream>
using namespace std;
class Singleton {
   static Singleton *instance;
   int data;
 
   // Private constructor so that no objects can be created.
   Singleton() {
      data = 0;
   }
   public:
   static Singleton *getInstance() {
      if (!instance)
      instance = new Singleton;
      return instance;
   }
   int getData() {
      return this -> data;
   }
   void setData(int data) {
      this -> data = data;
   }
};
//Initialize pointer to zero so that it can be initialized in first call to getInstance
Singleton *Singleton::instance = 0;
int main(){
   Singleton *s = s->getInstance();
   cout << s->getData() << endl;
   s->setData(100);
   cout << s->getData() << endl;
   return 0;
}
