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


void traverseInOrder(TreeNode *temp) {
  if (temp == NULL)
  { return;
  }
    traverseInOrder(temp->left);
    cout<< temp->val<<"\t";
    traverseInOrder(temp->right);
}

bool issymmetricalhelp(TreeNode *left, TreeNode *right)
{

    if (left==NULL || right ==NULL)
    {
      return left ==right;
    }

    if(left->val!=right->val)
      return false;
    return issymmetricalhelp(left->left,right->right)&&issymmetricalhelp(left->right,right->left);
}

bool issymmetrical(TreeNode *root)
{
  return NULL || issymmetricalhelp(root->left,root->right);
}

string areMirrors(TreeNode *root1, TreeNode *root2)
{
    stack<TreeNode*> st1, st2;
    while (1)
    {
        while (root1 && root2)
        {
            if (root1->val != root2->val)
                return "No";                
            st1.push(root1);
            st2.push(root2);
            root1 = root1->left;
            root2 = root2->right;    
        }
          
        // if at any point one root becomes null and
        // the other root is not null, then they are 
        // not mirrors. This condition verifies that
        // structures of tree are mirrors of each other.
        if (!(root1 == NULL && root2 == NULL))
            return "No";
              
        if (!st1.empty() && !st2.empty())
        {
            root1 = st1.top();
            root2 = st2.top();
            st1.pop(); 
            st2.pop();
              
            /* we have visited the node and its left subtree.
               Now, it's right subtree's turn */
            root1 = root1->right;
              
            /* we have visited the node and its right subtree.
               Now, it's left subtree's turn */
            root2 = root2->left;
        }    
          
        // both the trees have been completely traversed
        else
            break;
    }
      
    // trees are mirrors of each other
    return "Yes";
}

void mirrorify(TreeNode* root, TreeNode** mirror)//create mirror tree
{
    if (root == NULL) 
    {
        mirror = NULL;
        return ;
    }
 
    // Create new mirror node from original tree node
    *mirror = new TreeNode(root->val);
    mirrorify(root->left, &((*mirror)->right));
    mirrorify(root->right, &((*mirror)->left));
}
//convert to mirror
void mirror_convert(TreeNode* node) 
{
    if (node == NULL) 
        return; 
    else
    {
       TreeNode* temp;
          
        /* do the subtrees */
        mirror_convert(node->left);
        mirror_convert(node->right);
      
        /* swap the pointers in this node */
        temp     = node->left;
        node->left = node->right;
        node->right = temp;
    }
} 

int main()
{
 TreeNode* root= new TreeNode(4);
 root->left=new TreeNode(6);
 root->right=new TreeNode(6);
  // root->left->left=new TreeNode(7);
 // root->left->left->left=new TreeNode(8);
 // root->left->left->left->right=new TreeNode(9);
 // root -> left -> right =new  TreeNode(10);
 // root -> left -> left -> right =new  TreeNode(14);
 // root -> left -> left -> right -> right =new  TreeNode(13);
 // root -> right -> left =new  TreeNode(11);
 root -> right -> right =new  TreeNode(7);
traverseInOrder(root);
cout<<endl;

 TreeNode* soot= new TreeNode(4);
 soot->left=new TreeNode(6);
 soot->right=new TreeNode(6);
  soot->left->left=new TreeNode(7);
 
 // issymmetrical(root)?cout<<"yes":cout<<"no"; // check symmetrical
 // issymmetricalhelp(root,soot)?cout<<"yes":cout<<"no"; //check Mirror of two tree

 TreeNode *mirror=NULL;
 mirrorify(root,&mirror);
// traverseInOrder(mirror);

mirror_convert(root);
traverseInOrder(root);



}