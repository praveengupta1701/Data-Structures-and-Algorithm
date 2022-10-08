#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define size 10
struct stack
{
int item[size];
int top;
}s;
void intializestack()
{
    s.top=-1;
}
void push(int key)
{
    if(s.top==size-1)
    {
        printf("stack overflow");
        exit(1);
    }
    s.top++;
    s.item[s.top]=key;
}
int empty()
{
    if (s.top==-1)
        return (TRUE);
    else
        return (FALSE);
}
int pop()
{
    if(empty())
    {
        printf("stack underflow");
        exit(1);
    }  int x;
    x=s.item[s.top];
    s.top--;
    return x;
}
int stacktop()
{
    return(s.item[s.top]);
}
int main()
{
int t;
intializestack();
push(15);
push(17);
int d;
d=pop();
printf("%d",d);
}
