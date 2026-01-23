#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  struct Node* left;
  struct Node* right;
  Node(int val)
  {
    data=val;
    left=right=nullptr;
  }

};
typedef struct Node TreeNode;

int max_path(TreeNode *root,int &ans)
{
  if(root==NULL)    return 0;
  //Avoid negative as they won't help maximize
  int left_sum=max(0,max_path(root->left, ans));
  int right_sum=max(0,max_path(root->right, ans));
  ans=max(ans,left_sum+right_sum  +root->data);
  return max(left_sum,right_sum)+root->data;
}
int max_path_sum(TreeNode *root)
{
  int ans=INT_MIN;
 cout<<"max_path "<< max_path(root,ans)<<"\n";
  return ans;
}
int main()
{
  struct Node* root =new Node(1);

  root->left =new Node(2);
  root->right =new Node(3);
  root->left->right =new Node(10);

  root->left->left =new Node(20);
   root->left->left->left =new Node(8);
   root->left->left->left->left=new Node(9);
  root->right->left =new Node(6);
  root->right->right =new Node(20);
  root->right->right->right =new Node(12);
    root->right->right->right->right =new Node(11);
  cout<<"max_sum = "<<max_path_sum(root)<<"\n";
  
}