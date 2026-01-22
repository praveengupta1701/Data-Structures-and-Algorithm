/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

struct time
{
    int start;
    int final;
};

int count =0;
 int  recur(struct time *a,struct time *b)
  {
       if(*a==NULL)
      return;
      if(a.final>b.start)
      {
          recur(a->next,n->next);
      }
      
      return 1+   recur(a->next,n->next);
      
  }






int main()
{
    struct time k[20];
    k[0].start=0;
    k[1].final=2;
    // b=a->next;
    // recur(a,b)

    return 0;
}