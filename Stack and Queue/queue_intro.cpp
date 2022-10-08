/***********Program  Queue/***********Program for Circular Queue**************/

/***********Developer:Praveen Gupta,CSEC1,1703210110**************/

/***********Processor Directive*******/
#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

struct queue
{
    char item[SIZE];
    int REAR;
    int FRONT;
}q;

void intialize()
{
    q.REAR=-1;
    q.FRONT=0;
}

int empty1()
{
if( q.REAR-q.FRONT+1==0)
    return 1;
else
    return 0;
}

void enqueue(char key)
{
    if (q.REAR==SIZE)
    {

     printf("queue overflows");
    exit(1);
    }
    //printf("\n%c",key);
    q.REAR=(q.REAR+1);
    q.item[q.REAR]=key;
}

char dequeue()
{
    if(empty1())
    {
        printf("queue underflow");
        exit(1);
    }
    char x;
     q.FRONT=(q.FRONT+1);
     x=q.item[q.FRONT];
     //printf("\n\n%c",x);
    return x;
}

int main()
{
    intialize();
    enqueue('A');
    enqueue('B');
    enqueue('i');
    char x;
    x=dequeue();
    printf("%c",x);
    enqueue('i');
    enqueue('i');enqueue('i');enqueue('i');enqueue('i');enqueue('i');enqueue('i');
}
