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
node * constructTree(vector < int > & inorder, int inStart, int inEnd,vector < int > & postorder, int postStart, int postEnd, map < int, int > & mp) {
  if (postStart > postEnd || inStart > inEnd) return NULL;

  node * root = newNode(postorder[postEnd]);
  int elem = mp[postorder[postEnd]];
  int nElem = elem - inStart;

  root->left = constructTree( inorder,inStart, elem - 1,postorder, postStart , postStart + nElem-1, mp);
  root->right = constructTree( inorder,elem + 1, inEnd,postorder, postStart + nElem , postEnd -1, mp);

  return root;
}

node * buildTree(vector < int > & postorder, vector < int > & inorder) {
  int postStart = 0, postEnd = postorder.size() - 1;
  int inStart = 0, inEnd = inorder.size() - 1;

 if(inorder.size()!=postorder.size())
  return NULL;
  map < int, int > mp;
  for (int i = inStart; i <= inEnd; i++) {
    mp[inorder[i]] = i;
  }

  return constructTree(inorder, inStart, inEnd,postorder, postStart, postEnd,  mp);
}

int main() {

  vector<int> preorder{10,20,40,50,30,60};
  vector<int> inorder{40,20,50,10,60,30};
  node * root = buildTree(preorder, inorder);
  return 0;
}