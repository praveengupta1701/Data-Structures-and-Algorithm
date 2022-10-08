/***********Program for Priorty Queue using Max Heap **************/
/***********Developer:Praveen Gupta,CSEC1,1703210110**************/
/***********Processor Directive*******/
#include<bits/stdc++.h>
using namespace std;
#include<stdio.h>
void exchange(int *a,int *b)
{
    int temp=0;
    temp=*a;
    *a=*b;
    *b=temp;
}
/***************************adjust**********************/
void heapify(int arr[], int N, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < N && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < N && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, N, largest);
    }
}
 
/************************for maxheapify******************/
void maxheapify(int a[],int n)
{ 
    int start_index=n/2-1;

    for(int i=start_index;i>=0;i--)
       {
           heapify(a,n,i);
       }
}


/**************************for heap insertion*************************/
int heapinsertion(int a[],int n,int key)
{
    
    a[n]=key;
    int i=n;
    while(i>1&&a[i]>a[i/2])
    {
        swap(a[i],a[i/2]);
        i=i/2;
    }
    return n;
}  /****************************for heap deletion*************************/
int heapdeletion(int a[],int n)
{int i;
   printf("\ndeleted element=%d\n",a[1]);
  for(i=0;i<n-2;i++)
  {
      a[i]=a[i+1];
  }
  n=n-1;
  heapify(a,1,n);
  return n;
}
/*********************************traverse***************************/
void traverse(int a[],int n)
{
    int i;
    //printf(“\n”);
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}
int main()
{
    int a[]={55,22,33,54,17,222,345,232,12,23};
     int n = sizeof(a) / sizeof(a[0]);
        maxheapify(a,n);
       traverse(a,n);
       printf("\n");
    n=heapinsertion(a,n,444);
     traverse(a,n);
       printf("\n");

    n=heapinsertion(a,n,41);
     traverse(a,n);
       printf("\n");
     
    n=heapinsertion(a,n,28);
      n=heapdeletion(a,n);
      printf(" Value of n = %d\n",n);
      traverse(a,n);
  return 0;
}

