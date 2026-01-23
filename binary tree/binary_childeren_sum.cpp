#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

void inorder(struct node* root)
{
  if(root==NULL)
  {
    return ;
  }
  inorder(root->left);
  cout<<root->data<<"\t";
  inorder(root->right);
}

bool isChildSum(struct node * root) {
    if (!root || (!root->left && !root->right))
        return true;

int left = root->left ? root->left->data : 0;
    int right = root->right ? root->right->data : 0;

return (root->data == left + right) &&
           isChildSum(root->left) &&
           isChildSum(root->right);
}

void reorder(node * root) {
  if (root == NULL) return;
  int child = 0;
  if (root -> left) {
    child += root -> left -> data;
  }
  if (root -> right) {
    child += root -> right -> data;
  }

  if (child < root -> data) {
    if (root -> left) root -> left -> data = root -> data;
    else if (root -> right) root -> right -> data = root -> data;
  }

  reorder(root -> left);
  reorder(root -> right);

  int tot = 0;
  if (root -> left) tot += root -> left -> data;
  if (root -> right) tot += root -> right -> data;
  if (root -> left || root -> right) root -> data = tot;
}
void changeTree(node * root) {
  reorder(root);
}

struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}

int main() {

  struct node * root = newNode(2);
  root -> left = newNode(35);
  root -> left -> left = newNode(2);
  root -> left -> right = newNode(3);
  root -> right = newNode(10);
  root -> right -> left = newNode(5);
  root -> right -> right = newNode(2);
  inorder(root);
cout<<"\ntransforming \n";
  changeTree(root);  // changing tree to children form
  inorder(root);

  if(isChildSum(root))
  {
    cout<<"\nchildsumtree";
  }
  return 0;
}