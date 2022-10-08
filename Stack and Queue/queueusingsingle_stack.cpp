Last chance to avail FLAT (35% + 20%) Off on all Coding Ninjas Courses| Enrol Now
Skip to content
takeUforward
~ Strive for Excellence

Striver’s A2Z DSA Course/Sheet
Striver’s SDE Sheet
Striver’s DP Series
CS Subjects
SDE Core Sheet
Operating Systems
Computer Networks
Programming
Learn C++
C++ STL
C Programs
Data Structure
Interview Prep
Blind 75
Striver Tree Series
Striver’s CP Sheet
TCS NQT Coding Sheet
Interview Experience
Interview Prep Roadmap
Courses
December 7, 2021 Data Structure / Queue / Stack
Implement Queue using Stack
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
int main() {
  Queue q;
  q.Push(3);
  q.Push(4);
  cout << "The element poped is " << q.Pop() << endl;
  q.Push(5);
  cout << "The top of the queue is " << q.Top() << endl;
  cout << "The size of the queue is " << q.size() << endl;
}