
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


void alldfs_travelsal(struct Node* root)
{
	stack<pair<struct Node*,int>> st;
	if(root==NULL)
	{
		return ;
	}
	st.push({root,1});
	vector<int> pre,in,post;
	while(!st.empty())
	 {
		auto it=st.top();
		st.pop();
		switch(it.second)
		{
			case 1:
			pre.push_back(it.first->data);
			it.second++;
			st.push(it);
			if(it.first->left!=NULL)
				st.push({it.first->left,1});
			break;
			case 2:
			in.push_back(it.first->data);
			it.second++;
			st.push(it);
			if(it.first->right!=NULL)
				st.push({it.first->right,1});
				break;
			case 3: 
			post.push_back(it.first->data);
		}

	}
	for(auto x:pre)
	{
		cout<<x<<"\t";
	}
	cout<<endl;
	for(auto x:in)
	{
		cout<<x<<"\t";
	}
	cout<<endl;
	for(auto x:post)
	{
		cout<<x<<"\t";
	}
	cout<<endl;
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
  //	alldfs_travelsal(root);
}