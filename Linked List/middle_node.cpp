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

    
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next)
            slow = slow->next, fast = fast->next->next;
        return slow;
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
    // ans=s.reverseList(root);
    s.display(ans);




    return 0;
}



