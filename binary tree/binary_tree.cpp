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
void preorder(struct Node* root)
{
	if(root==NULL)
	{
		return ;
	}
	cout<<root->data<<"\t";
	preorder(root->left);
	preorder(root->right);
}
void inorder(struct Node* root)
{
	if(root==NULL)
	{
		return ;
	}
	inorder(root->left);
	cout<<root->data<<"\t";
	inorder(root->right);
}

void postorder(struct Node* root)
{
	if(root==NULL)
	{
		return ;
	}
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<"\t";
}

int maxdepth(struct Node* root)
{
	if(root==NULL)return 0;
	int lh=maxdepth(root->left);
	int rh=maxdepth(root->right);
	return 1+max(lh,rh);
}

/********************************** BalancedBT***************/
int height_balanced(TreeNode* root)
    {
    if(root==NULL)return 0;
	int lh=height_balanced(root->left);
     if(lh==-1)return -1;
	int rh=height_balanced(root->right);
	if(rh==-1)return -1;
	if(abs(lh-rh)>1)return -1;
	return 1+max(lh,rh);
    }
    bool isBalanced(TreeNode* root) 
    {
     return (height_balanced(root)!=-1);   
    }
/**********************Diameter*******************************/
int height(TreeNode* root, int &diameter)
{
	if(root==NULL)return 0;
	int lh=height(root->left,diameter);
	int rh=height(root->right,diameter);
	diameter=max(diameter,lh+rh);
	return 1+max(lh,rh);
}
int diameterBT(TreeNode* root)
{
	int diameter=0;
	height(root,diameter);
	return diameter;

}
/********************************************************/

/*******************count nodes in tree**********/
int countnodes(TreeNode* root)
{
	if(root==NULL)		return 0;
	else
		return 1+countnodes(root->left)+countnodes(root->right);
}

int countleafs(TreeNode* root)
{
	if(root==NULL)		
		return 0;
	else if(root->left==NULL&&root->right==NULL)
		return 1;
	else
		return countleafs(root->left)+countleafs(root->right);

}
/*************************same tree**************/
bool isIdentical(TreeNode* p,TreeNode* q)
{
	if(p==NULL||q==NULL)		return (p==q);
	return(p->data==q->data)&&(isIdentical(p->left,q->left))&&(isIdentical(p->right,q->right));
}

int main()
{
	struct Node* root =new Node(1);

	root->left =new Node(2);
	root->right =new Node(3);
	//root->left->right =new Node(10);

 	//root->left->left =new Node(-20);
 // 	root->left->left->left =new Node(8);
 // 	root->left->left->left->left=new Node(9);
	// root->right->left =new Node(6);
	// root->right->right =new Node(4);
	// root->right->right->right =new Node(5);
 //    root->right->right->right->right =new Node(11);
	
	struct Node* soot =new Node(1);
	soot->left =new Node(2);
	soot->right =new Node(3);
	soot->left->right =new Node(10);

	 preorder(root);
	 cout<<"\n";
	// inorder(root);
	// cout<<"\n";
	// postorder(root);
	// cout<<"\n";
	//levelorder(root);
	 cout<<height_balanced(root)<<"\n";
//	alldfs_travelsal(root);
	 cout<<maxdepth(root);
	 isBalanced(root)?cout<<"BalancedBT \n":cout<<"Not BalancedBT \n";
	cout<<"\ndiameter \t"<<diameterBT(root)<<"\n";
	//cout<<"max_sum = "<<max_path_sum(root)<<"\n";
	// cout<<"count nodes "<<countnodes(root)<<" countleafs "<<countleafs(root);
	// isIdentical(root,soot)?cout<<"identical":cout<<"not_same"<<endl;
}

