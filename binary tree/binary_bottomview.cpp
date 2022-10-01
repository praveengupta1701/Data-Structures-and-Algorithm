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

vector<int> Topview(TreeNode * root)
{
  vector<int> ans;
  if(root==NULL) return ans;
  map<int,int>  m;
  queue<pair<TreeNode*,int>> q;
  q.push({root,0});
  while(!q.empty())
  {
    auto it=q.front();
    q.pop();
    TreeNode* node=it.first;
    int level =it.second;
      m[level]=node->data;
    if(node->left)
      q.push({node->left,level-1});
    if(node->right)
      q.push({node->right,level+1});
  }
  for(auto x:m)
  {
    ans.push_back(x.second);
    cout<<x.second<<"\t";
  }
  return ans;

}

int main()
{
	struct Node* root =new Node(1);

	root->left =new Node(2);
	root->right =new Node(3);
	root->left->right =new Node(10);

 	root->left->left =new Node(4);
 	root->left->left->left =new Node(8);
 	root->left->left->left->left=new Node(9);
	root->right->left =new Node(6);
	root->right->right =new Node(7);
	root->right->right->right =new Node(12);
  root->right->right->right->right =new Node(11);

  Topview(root);
}