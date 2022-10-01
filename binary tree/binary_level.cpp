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

/******************************************************/

vector<vector<int>> levelorder(struct Node* root)
{
    vector<vector<int>> ans;
    if(root==NULL)
    {
        return ans;
    }
    
    queue<struct Node*> q;
    q.push(root);
    while(!q.empty())
    {
        int size =q.size();
        vector<int> level;
        for (int i = 0; i < size; ++i)
        {
            struct Node* node=q.front();
            q.pop();
            if(node->left!=NULL) q.push(node->left);
            if(node->right!=NULL) q.push(node->right);
            level.push_back(node->data);
            cout<<node->data<<"\t";
        }
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
 // 	root->left->left->left =new Node(8);
 // 	root->left->left->left->left=new Node(9);
	// root->right->left =new Node(6);
	// root->right->right =new Node(-20);
	// root->right->right->right =new Node(12);
 //    root->right->right->right->right =new Node(11);
}