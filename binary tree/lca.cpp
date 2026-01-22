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

//method 1:
bool getpath(TreeNode *root,vector<int> &v,int data) //finding node is present or not
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




std::vector<int>  getpathnode(TreeNode *root, int data)  // path to node
{
  std::vector<int> v;
  if(root == NULL)
    return v;
  if(getpath(root,v,data))
  {
    cout<<"\npresent node\n";
  }
  else
  {
    cout<<"\n not present\n";
  }
  return v;
}

int lca(TreeNode *root, int a,int b)

{ 
   if(root == NULL)
    return 0 ;
  vector<int> a1=getpathnode(root,a);
  vector<int> b1=getpathnode(root,b);
int ans=0;
  for(auto i=0;i<a1.size();i++)
  {
    if(a1[i]==b1[i])
    {
      ans=a1[i];
    }
    else
    {
      break;
    }
  }
  return ans;

}


//method 2:

TreeNode* lca_fast(TreeNode *root, TreeNode *p,TreeNode  *q)
{
  if(root == NULL||root==p||root==q)
  {
    return root ;
  }
  TreeNode *left=lca_fast(root->left,p,q);
  TreeNode *right=lca_fast(root->right,p,q);
  if(left==NULL&&right!=NULL)
    return right;
  else if(right==NULL&&left!=NULL)
    return left;
  else
  {//both left  and right ar not null
    return root;
  }
}
int main()
{
  //   #ifndef ONLINE_JUDGE    
  //   freopen("input.txt", "r", stdin);
  //   freopen("output.txt", "w", stdout);
  // #endif
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
 root->right->right =new  TreeNode(8);
// traversePreOrder(root);
  
   std::vector<int> res=getpathnode(root,13);
  for_each(res.begin(),res.end(),[](int x){cout<<x<<" ";});
  cout<<"\n";
  // int k=lca(root,13,9);
  // cout<<k<<" ";
 TreeNode *p,*q;
 q=root->left->left;
 p=root->right->right;
 //cout<<"p "<<p->val<<" q "<<q->val<<" ";
// cout<<lca_fast(root,p,q)->val;
 
}