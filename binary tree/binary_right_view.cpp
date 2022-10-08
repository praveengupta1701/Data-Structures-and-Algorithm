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
void right_view(TreeNode *root, int level, vector<int> &res)
{
    if(root==NULL)
    {
        return ;
    }

    if(level==res.size())
        res.push_back(root->data);
    right_view(root->right,level+1,res); //1.
    right_view(root->left,level+1,res);//2.
    //for left view made 2. line abov of 1.line 

}

vector<int> rightsideview(TreeNode *root)
{
    vector<int> res;
    right_view(root,0,res);
    return res;
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
    root->right->left->left =new Node(13);
    root->right->left->left->left =new Node(16);
    root->right->left->left->left->left =new Node(26);
    root->right->left->left->left->left->left =new Node(366);
	root->right->right =new Node(7);
	root->right->right->right =new Node(12);
    root->right->right->right->right =new Node(11);
    vector <int> res=rightsideview(root);

    for_each(res.begin(),res.end(),[](int i){cout<<i<<" ";});
}