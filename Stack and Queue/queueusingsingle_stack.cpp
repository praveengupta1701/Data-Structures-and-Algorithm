/*
Problem Statement: Given a Stack having some elements stored in it. Can you implement a
Queue using the given Stack?

Queue: A Queue is a linear data structure that works on the basis of FIFO(First in First out). This means the element added at first will be removed first from the Queue.

Disclaimer: Don’t jump directly to the solution, try it out yourself first.

Solution 1: Using two Stacks where push operation is O(N)

Approach:



push(x) ->



pop()->



top()->



size()->

size() operation is for returning the size of a queue which can be done by using the function Stack1. size(). It will actually return the total number of elements in the queue.

Code:
*/
#include <bits/stdc++.h>

using namespace std;

struct Queue {
  stack < int > input, output;
  
  // Push elements in queue
  void Push(int data) {
    // Pop out all elements from the stack input
    while (!input.empty()) {
      output.push(input.top());
      input.pop();
    }
    // Insert the desired element in the stack input
    cout << "The element pushed is " << data << endl;
    input.push(data);
    // Pop out elements from the stack output and push them into the stack input
    while (!output.empty()) {
      input.push(output.top());
      output.pop();
    }
  }
  // Pop the element from the Queue
  int Pop() {
    if (input.empty()) {
      cout << "Stack is empty";
      exit(0);
    }
    int val = input.top();
    input.pop();
    return val;
  }
  // Return the Topmost element from the Queue
  int Top() {
    if (input.empty()) {
      cout << "Stack is empty";
      exit(0);
    }
    return input.top();
  }
  // Return the size of the Queue
  int size() {
    return input.size();
  }
};

class MyQueue {
public:
    stack <int> input,output;
     void push(int x) {
        input.push(x);
    }
  // Remove the element from the front of the queue and returns it...
    int pop() {
        peek();
       int val = output.top();
        output.pop();
        return val;
    }
  // Get the front element...
    int peek() {
        if (output.empty())
        while (!input.empty())
            output.push(input.top()), input.pop();
        return output.top();
    }
  // Return whether the queue is empty...
    bool empty() {
        return input.empty() && output.empty();
    }
    int size() {
    return (output.size() + input.size()); 
  }

};
  
int main() {
  Queue q;
  q.Push(3);
  q.Push(4);
  cout << "The element poped is " << q.Pop() << endl;
  q.Push(5);
  cout << "The top of the queue is " << q.Top() << endl;
  cout << "The size of the queue is " << q.size() << endl;
}