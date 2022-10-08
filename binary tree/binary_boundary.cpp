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
/****************************Boundary Traversal Anti Cloackwse******************/
bool isLeaf(TreeNode * root) {
  return !root -> left && !root -> right;
}

void addLeftBoundary(TreeNode * root, vector < int > & res) //excluding leafs
{// for adding root directly print root
  TreeNode * cur = root -> left;
  while (cur) {
    if (!isLeaf(cur)) res.push_back(cur -> data);
    if (cur -> left) cur = cur -> left;
    else cur = cur -> right;
  }
}
void addRightBoundary_in_reverse(TreeNode * root, vector < int > & res)// in reverse order excluding leafs
 {// for adding root directly print root
  TreeNode * cur = root -> right;
  vector < int > tmp;
  while (cur) {
    if (!isLeaf(cur)) tmp.push_back(cur -> data);
    if (cur -> right) cur = cur -> right;
    else cur = cur -> left;
  }
  for (int i = tmp.size() - 1; i >= 0; --i) {
    res.push_back(tmp[i]);
  }
}

void addLeaves(TreeNode * root, vector < int > & res) // only leave traversal from left to right
{
  if (isLeaf(root)) {
    res.push_back(root -> data);
    return;
  }
  if (root -> left) addLeaves(root -> left, res);
  if (root -> right) addLeaves(root -> right, res);
}
/****************************Main Code********************/
vector < int > printBoundary(TreeNode * root) {
  vector < int > res;
  if (!root) return res;


  // root node
  if (!isLeaf(root)) res.push_back(root -> data);

//1.addLeftBoundary exluding leaf and root node

  addLeftBoundary(root, res);

  // add leaf nodes
  addLeaves(root, res);
//1.add right Boundary exluding leaf in reverse order
  addRightBoundary_in_reverse(root, res);

  for (auto x:res)
  {
    cout<<x<<"\t";
  }
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
	root->right->right =new Node(7);
	root->right->right->right =new Node(12);
    root->right->right->right->right =new Node(11);
   // printBoundary(root);

    vector<int>  res;
    // addLeaves(root,res);
   // addLeftBoundary(root,res);//addLeftBoundary exluding leaf and root node
    addRightBoundary_in_reverse(root,res);//add right Boundary exluding leaf and root node in reverse order
    for(auto x:res)
    {
        cout<<x<<"\t";
    }

}