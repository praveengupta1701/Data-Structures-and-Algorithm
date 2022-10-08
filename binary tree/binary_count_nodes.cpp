#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};


struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}

void inOrderTrav(node * curr, int& count) {
  if (curr == NULL)
    return;

  count++;
  inOrderTrav(curr -> left, count);
  inOrderTrav(curr -> right, count);
}
 
    int findHeightLeft(node* cur) {
        int hght = 0; 
        while(cur) {
            hght++; 
            cur = cur->left; 
        }
        return hght; 
    }
    int findHeightRight(node* cur) {
        int hght = 0; 
        while(cur) {
            hght++; 
            cur = cur->right; 
        }
        return hght; 
    }
    int countNodes(node* root) {
        if(root == NULL) return 0; 
        
        int lh = findHeightLeft(root); 
        int rh = findHeightRight(root); 
        
        if(lh == rh) return (1<<lh) - 1; 
        
        int leftNodes = countNodes(root->left);
        int rightNodes = countNodes(root->right);
        
        return 1 + leftNodes + rightNodes; 
    }

int main() {

  struct node * root = newNode(1);
  root -> left = newNode(2);
  root -> right = newNode(3);
  root -> left -> left = newNode(4);
  root -> left -> right = newNode(5);
  root -> right -> left = newNode(6);
  root -> right -> right = newNode(7);
  root -> left -> left -> left = newNode(8);
  root -> left -> left -> right = newNode(9);
  root -> left -> right -> left = newNode(10);
  root -> left -> right -> right = newNode(11);


  cout << "The total number of nodes in the given complete binary tree are: "
  <<countNodes(root);
  return 0;
}