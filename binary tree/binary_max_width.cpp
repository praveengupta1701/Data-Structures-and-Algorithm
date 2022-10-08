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

int max_width(TreeNode *root)
{
  if (root == NULL)
  { return 0;
  }
 int ans=1;
    queue<pair<TreeNode*,int>> q;
    q.push({root,0});
    while(!q.empty())
    {
        int size =q.size();
        int mmin=q.front().second;
        int first,last;
        for (int i = 0; i < size; ++i)
        {
          int curr_id=q.front().second-mmin;
           TreeNode* node=q.front().first;
            q.pop();
            if (i==0) first=curr_id;
            if(i==size-1) last=curr_id;
            if(node->left!=NULL) q.push({node->left, curr_id*2+1});
            if(node->right!=NULL) q.push({node->right,curr_id*2+2});
        }
        ans=max(ans,last-first+1);
    }
    return ans;
}

int main()
{
 TreeNode* root= new TreeNode(4);
 root->left=new TreeNode(6);
 root->right=new TreeNode(5);
 root->left->left=new TreeNode(7);
 // root->left->left->left=new TreeNode(8);
 // root->left->left->left->right=new TreeNode(9);
 // root -> left -> right =new  TreeNode(10);
 // root -> left -> left -> right =new  TreeNode(14);
 // root -> left -> left -> right -> right =new  TreeNode(13);
 root -> right -> left =new  TreeNode(11);
 root -> right -> left->left =new  TreeNode(15);

 // root -> right -> right =new  TreeNode(8);
// traversePreOrder(root);
cout<<max_width(root);
}