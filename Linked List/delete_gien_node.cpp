

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

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 

class Solution {
public:



    void display(ListNode* root)
    {
        if(root ==NULL)
            return ;
        cout<<endl;
        while(root!=NULL)
        {
            cout<<root->val<<"\t";
            root=root->next;

        }
    }
    void deleteNode(ListNode* t) 
    {
    t->val = t->next->val;

    if(t->next->next ==NULL)
    {
        t->next=NULL;
    }
    else
    {
    ListNode *temp;
    temp=t->next;
    t->next = temp->next;
    free(temp);
    }
}
};


int32_t main()
{   
    #ifndef ONLINE_JUDGE    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ListNode *root=new ListNode(5);
    root->next=new ListNode(7);
    root->next->next=new ListNode(6);
    root->next->next->next=new ListNode(8);
    root->next->next->next->next=new ListNode(10);
    root->next->next->next->next->next=new ListNode(2);


    Solution s;
    s.display(root);
    ListNode *ans;
    // ans=s.reverseList(root);
    //ans=s.removeNthFromEnd(root,3);  //remove  3th node from end
    ans=root->next->next->next->next;
    s.deleteNode(ans); //delete a given node
    s.display(root);


     int x=1;
     const auto k=x;

    return 0;
}



