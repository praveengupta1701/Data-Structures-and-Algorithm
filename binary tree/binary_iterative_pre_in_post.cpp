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


vector<int> iterative_preorder(struct Node* root)
{
	vector<int> pre_order;
	if(root==NULL)
	{
		return pre_order;
	}
	stack<struct Node* > s;
	s.push(root);
	while(!s.empty())
	{
		root=s.top();
		s.pop();
		pre_order.push_back(root->data);
		cout<<root->data<<"\t";
		if(root->right!=NULL) s.push(root->right);//stack FILO
		if(root->left!=NULL) s.push(root->left);
	
	}
	cout<<"\n";
	return pre_order;
}

vector<int> iterative_inorder(struct Node* root)
{
	vector<int> in_order;
	if(root==NULL)
	{
		return in_order;
	}
	struct Node* node=root;
	stack<struct Node*> s;
	while(true)
	{
		if(node!=NULL)//AUXILLARY SPACE 
		{
			s.push(node);
			node=node->left;
		}
		else
		{
			if(s.empty()==true)
				break;
			node=s.top();
			s.pop();
			in_order.push_back(node->data);
			cout<<node->data;
			node=node->right;
		}
	}
	cout<<"\n";
	return in_order;
}


vector<int> iterativePostorderWithTwoStack(struct Node* root)
{
	vector<int> post_order;
	if(root==NULL)
	{
		return post_order;
	}
	stack<struct Node*> st1,st2;
	st1.push(root);
	while(!st1.empty())
	{
		root=st1.top();
		st1.pop();
		st2.push(root);
		if(root->left!=NULL) st1.push(root->left);
		if(root->right!=NULL) st1.push(root->right);//stack FILO
	}
	while(!st2.empty())
	{
		post_order.push_back(st2.top()->data);
		cout<<st2.top()->data<<"\t";
		st2.pop();
	}
	return post_order;
}

vector<int> iterativePostorderWithOneStack(struct Node* root)	
{
	vector<int> post_order;
	if(root==NULL)
	{
		return post_order;
	}
	stack<struct Node*> s;
	struct Node *curr,*temp;
	curr=root;
	while(curr!=NULL||!s.empty())
	{
		if(curr!=NULL)
		{
			s.push(curr);
			curr=curr->left;
		}
		else
		{
			temp=s.top()->right;
			if(temp==NULL)
			{
				temp=s.top();
				s.pop();
				post_order.push_back(temp->data);
				cout<<temp->data<<"\t";

				while(!s.empty()&&temp==s.top()->right)
				{

				temp=s.top();
				s.pop();
				post_order.push_back(temp->data);
				cout<<temp->data<<"\t";				
				}
			}
			else
				curr=temp;
			}
		}
	return post_order;
}

int main()
{
	struct Node* root =new Node(1);

	root->left =new Node(2);
	root->right =new Node(3);
	root->left->right =new Node(10);

 	root->left->left =new Node(-20);
 // 	root->left->left->left =new Node(8);
 // 	root->left->left->left->left=new Node(9);
	// root->right->left =new Node(6);
	// root->right->right =new Node(-20);
	// root->right->right->right =new Node(12);
 //    root->right->right->right->right =new Node(11);
 	//	iterative_preorder(root);
    //iterative_inorder(root);
   // iterativePostorderWithTwoStack(root);
   // iterativePostorderWithOneStack(root);	
}