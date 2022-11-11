// Created by ...
/* Author -Praveen Gupta*/

#include <bits/stdc++.h>
#include <thread>
#include <mutex>
#include <chrono>
#include <memory>
#include <condition_variable>
using namespace std;
using namespace std::chrono;

//ACCEPTED


//slow but working
class LRUCache1 {
 public:
    
    unordered_map <int,int> m;
    unordered_map <int, list<int>::iterator> address;
    list <int> l;
    int cap;
    int size;
    LRUCache(int capacity)
    {
        cap =capacity;
        size=0;
     
    }
    
    int get(int key) {
      if(m.find(key)==m.end())// if key not found
          return -1;
        list<int>::iterator it=address[key];
        //deleting from position
        l.erase(it);
        address.erase(key);
        //inserting in begginning of list
        l.push_front(key);
        address[key]=l.begin();//storing address
        return m[key];
        
    }
    
    void put(int key, int value) 
    {
      if(m.find(key)!=m.end())//if already present in map
      {
          l.erase(address[key]);
          address.erase(key);
          m.erase(key);
          size--;
      }
        if(size==cap) //size equal to cap so we have to remove LRU
        {
            int k=l.back();
            l.pop_back();
            address.erase(k);
            m.erase(k);
            size--;
        }
        size++;
        l.push_front(key);
        address[key]=l.begin();
        m[key]=value;
        
        
    }
};

// It is slow
class LRUCache {
  public:
    class node {
      public:
        int key;
      int val;
      node * next;
      node * prev;
      node(int _key, int _val) 
      {
        key = _key;
        val = _val;
      }
    };

  node * head = new node(-1, -1);
  node * tail = new node(-1, -1);

  int cap;
  unordered_map < int, node * > m;

  LRUCache(int capacity) {
    cap = capacity;
    head -> next = tail;
    tail -> prev = head;
  }

  void addnode(node * newnode) {
    node * temp = head -> next;
    newnode -> next = temp;
    newnode -> prev = head;
    head -> next = newnode;
    temp -> prev = newnode;
  }

  void deletenode(node * delnode) {
    node * delprev = delnode -> prev;
    node * delnext = delnode -> next;
    delprev -> next = delnext;
    delnext -> prev = delprev;
   //  delete delnode;
  }

  int get(int key_) {
    if (m.find(key_) != m.end()) {
      node * resnode = m[key_];
      int res = resnode -> val;
      m.erase(key_);
      deletenode(resnode);
      addnode(resnode);
      m[key_] = head -> next;
      return res;
    }

    return -1;
  }

  void put(int key_, int value) {
    if (m.find(key_) != m.end()) {
      node * existingnode = m[key_];
      m.erase(key_);
      deletenode(existingnode);
    }
    if (m.size() == cap) {
      m.erase(tail -> prev -> key);
      deletenode(tail -> prev);
    }

    addnode(new node(key_, value));
    m[key_] = head -> next;
  }
};

int32_t main()
{   
  /* #ifndef ONLINE_JUDGE    
    freopen("C:\\Users\\Praveen\\Documents\\programs\\cpp\\input.txt", "r", stdin);
    freopen("C:\\Users\\Praveen\\Documents\\programs\\cpp\\output.txt", "w", stdout);
  #endif*/
    LRUCache s(3);
    s.put(3,2);
    s.put(6,7);
    s.put(4,3);
    cout<<s.get(6);
    s.put(5,4);

 


    return 0;
}