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

    ListNode* reverseList(ListNode* head) {

       //step 1
        ListNode* prev_p = NULL;
        ListNode* current_p = head;
        ListNode* next_p;
       
       //step 2
        while(current_p) {

            next_p = current_p->next;
            current_p->next = prev_p;
            
            prev_p = current_p;
            current_p = next_p;
        }

        head = prev_p; //step 3
        return head;
    }


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

    Solution s;
    s.display(root);
    ListNode *ans;
    ans=s.reverseList(root);
    s.display(ans);




    return 0;
}



