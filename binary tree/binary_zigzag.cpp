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

/****************zig-zag*******************/

vector<vector<int>> zigzagorder(struct Node* root)
{
  vector<vector<int>> ans;
  if(root==NULL)
    return ans;
  
  queue<TreeNode*> q;
  q.push(root);
  bool lefttoright=true;
  while(!q.empty())
  {
    int size =q.size();
    vector<int> level(size);
    for (int i = 0; i < size; ++i)
    {
      TreeNode* node=q.front();
      q.pop();
      if(node->left!=NULL) q.push(node->left);
      if(node->right!=NULL) q.push(node->right);
      int index=lefttoright?i:(size-i-1);        // main line for zig-zag
      level[index]=(node->data);
      cout<<node->data<<"\t";
    }
    lefttoright=!lefttoright;
    ans.push_back(level);
    cout<<"\n";
  }
  return ans;

} 


int main()
{
  struct Node* root =new Node(1);

  root->left =new Node(2);
  root->right =new Node(3);
  root->left->right =new Node(10);

  root->left->left =new Node(-20);
 //   root->left->left->left =new Node(8);
 //   root->left->left->left->left=new Node(9);
  // root->right->left =new Node(6);
  // root->right->right =new Node(-20);
  // root->right->right->right =new Node(12);
 //    root->right->right->right->right =new Node(11);
}