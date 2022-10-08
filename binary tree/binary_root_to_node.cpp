#include<bits/stdc++.h>
using namespace std;

struct binary_tree_clss
{
    int val;
    struct binary_tree_clss *left,*right;
    binary_tree_clss(int data)
{
    val=data;
    left=NULL;
   right=NULL;
}
};

typedef struct binary_tree_clss TreeNode;


void traversePreOrder(TreeNode *temp) {
  if (temp == NULL)
  { return;
  }
    cout<< temp->val<<"\t";
    traversePreOrder(temp->left);
    traversePreOrder(temp->right);
}


bool getpath(TreeNode *root,vector<int> &v,int data)
{
  if(root==NULL)
    return false;
  v.push_back(root->val);
  if(root->val==data)
  {
    return true;
  }
  if(getpath(root->left,v,data)||getpath(root->right,v,data))
  {
    return true;
  }
  v.pop_back();
  return false;
}




std::vector<int>  getpathnode(TreeNode *root, int data)
{
  std::vector<int> v;
  if(root == NULL)
    return v;
  getpath(root,v,data);
  return v;
}

int main()
{
 TreeNode* root= new TreeNode(4);
 root->left=new TreeNode(6);
 root->right=new TreeNode(5);
 root->left->left=new TreeNode(7);
 root->left->left->left=new TreeNode(8);
 root->left->left->left->right=new TreeNode(9);
 root -> left -> right =new  TreeNode(10);
 root -> left -> left -> right =new  TreeNode(14);
 root -> left -> left -> right -> right =new  TreeNode(13);
 root -> right -> left =new  TreeNode(11);
 root -> right -> right =new  TreeNode(8);
// traversePreOrder(root);
  
  std::vector<int> res=getpathnode(root,13);
  for_each(res.begin(),res.end(),[](int x){cout<<x<<" ";});
 
}