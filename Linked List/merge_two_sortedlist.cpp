

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

void insaft(ListNode **q,int key)
{
     ListNode *p;
     p=new ListNode(key);
     p->next=(*q)->next;
     (*q)->next=p;
}

void insbeg(ListNode **START,int key)
{
     ListNode *p,*temp;
     p=new ListNode(key);
     p->next=(*START);
     (*START)=p;
}
ListNode* mergelist(ListNode **S,ListNode **S1)
{
    ListNode *p,*q,*d,*k;
    p=*S;
    q=*S1;
    d=NULL;
    if(p->val<=q->val)
    {
        insbeg(&d,p->val);
        p=p->next;  
    }
    else
   {
        insbeg(&d,q->val);
        q=q->next;
   }
   k=d;
    while(p!=NULL&&q!=NULL)
    {
        if(p->val>q->val)
        {
              insaft(&d,q->val);
            d=d->next;
            q=q->next;
        }
  else
        {
             insaft(&d,p->val);;
            d=d->next;
            p=p->next;
        }
    }
    while(p!=NULL)
    {
         insaft(&d,p->val);
            d=d->next;
            p=p->next;
    }
    while(q!=NULL)
    {
     insaft(&d,q->val);
            d=d->next;
            q=q->next;
    }

    return k;
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        // when list1 is empty then 
        // our output will be same as list2
        if(l1 == NULL) return l2; 

        // when list2 is empty then our output 
        // will be same as list1
        if(l2 == NULL) return l1;

        // pointing l1 and l2 to smallest and greatest one
        if(l1->val > l2->val) std::swap(l1,l2);

        // act as head of resultant merged list
        ListNode* res = l1;

        while(l1 != NULL && l2 != NULL) {
 
            ListNode* temp = NULL;

            while(l1 != NULL && l1->val <= l2->val) {

                temp = l1;//storing last sorted node  
                l1 = l1->next;
            }

            // link previous sorted node with 
            // next larger node in list2
            temp->next = l2;
            std::swap(l1,l2);
        }

        return res;
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
    root->next->next=new ListNode(9);
    ListNode *soot=new ListNode(8);
    soot->next=new ListNode(10);
    soot->next->next=new ListNode(17);

    Solution s;
    s.display(root);
    s.display(soot);

    ListNode *ans;
    ans=s.mergelist(&root,&soot);
    s.display(ans);




    return 0;
}



