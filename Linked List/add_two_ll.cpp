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

     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(); 
        ListNode *temp = dummy; 
        int carry = 0;
        while( (l1 != NULL || l2 != NULL) || carry) {
            int sum = 0; 
            if(l1 != NULL) {
                sum += l1->val; 
                l1 = l1 -> next; 
            }
            
            if(l2 != NULL) {
                sum += l2 -> val; 
                l2 = l2 -> next; 
            }
            
            sum += carry; 
            carry = sum / 10; 
            ListNode *node = new ListNode(sum % 10); 
            temp -> next = node; 
            temp = temp -> next; 
        }
        return dummy -> next; 
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
    root->next->next->next=new ListNode(8);
    // root->next->next->next->next=new ListNode(10);
    // root->next->next->next->next->next=new ListNode(2);
    ListNode *soot=new ListNode(8);
    soot->next=new ListNode(9);
    soot->next->next=new ListNode(7);

    Solution s;
    s.display(root);
    ListNode *ans;
    // ans=s.reverseList(root);
    //ans=s.removeNthFromEnd(root,3);  //remove  3th node from end
    // ans=root->next->next->next->next;
    // s.deleteNode(ans); //delete a given node
    ans=s.addTwoNumbers(root,soot);
    s.display(ans);


     int x=1;
     const auto k=x;
     
    return 0;
}



