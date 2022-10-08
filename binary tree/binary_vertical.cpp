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

/*************************************/
/***************************issue is there with lower one is coming first then in case 12 9 in gfg ********************/

// Utility function to store vertical order in map 'm'
// 'hd' is horizontal distance of current node from root.
// 'hd' is initially passed as 0
void getVerticalOrder(TreeNode* root, int hd, map<int, vector<int>> &m)
{
    // Base case
    if (root == NULL)
        return;
 
    // Store current node in map 'm'
    m[hd].push_back(root->data);
 
    // Store nodes in left subtree
    getVerticalOrder(root->left, hd-1, m);
 
    // Store nodes in right subtree
    getVerticalOrder(root->right, hd+1, m);
}
 
// The main function to print vertical order of a binary tree
// with the given root
void printVerticalOrder_pre(TreeNode* root)
{
    // Create a map and store vertical order in map using
    // function getVerticalOrder()
    map < int,vector<int> > m;
    int hd = 0;
    getVerticalOrder(root, hd,m);
 
    // Traverse the map and print nodes at every horizontal
    // distance (hd)
    map< int,vector<int> > :: iterator it;
    for (it=m.begin(); it!=m.end(); it++)
    {
        for (int i=0; i<it->second.size(); ++i)
            cout << it->second[i] << " ";
        cout << endl;
    }
}
/****************************************************************************************/
/********************two element coming at same point is not orderd****************/
void printVerticalOrder_levelorder(TreeNode* root)
{
    // Base case
    if (!root)
        return;
 
    // Create a map and store vertical order in
    // map using function getVerticalOrder()
    map<int, vector<int> > m;
    int hd = 0;
 
    // Create queue to do level order traversal.
    // Every item of queue contains node and
    // horizontal distance.
    queue<pair<TreeNode*, int> > que;
    que.push(make_pair(root, hd));
 
    while (!que.empty()) {
        // pop from queue front
        pair<TreeNode*, int> temp = que.front();
        que.pop();
        hd = temp.second;
        TreeNode* node = temp.first;
 
        // insert this node's data in vector of hash
        m[hd].push_back(node->data);
 
        if (node->left != NULL)
            que.push(make_pair(node->left, hd - 1));
        if (node->right != NULL)
            que.push(make_pair(node->right, hd + 1));
    }
 
    // Traverse the map and print nodes at
    // every horizontal distance (hd)
    map<int, vector<int> >::iterator it;
    for (it = m.begin(); it != m.end(); it++) {
        for (int i = 0; i < it->second.size(); ++i)
            cout << it->second[i] << " ";
        cout << endl;
    }
}
 
/*********************LeetCODE*********************************/
vector<vector<int>> printVerticalOrder(TreeNode* root)
{
	vector<vector<int>> ans;
    // Base case
    if (!root)
        return ans;
    map<int,map<int, multiset<int>>> m;
    queue<pair<TreeNode*, pair<int,int> >> que;
    que.push({root, {0,0}});
    while (!que.empty()) 
    {
       auto temp = que.front();
        que.pop();
        TreeNode* node = temp.first;
 		int x=temp.second.first;
 		int y=temp.second.second;
        m[x][y].insert(node->data);
 
        if (node->left != NULL)
            que.push({node->left,{ x - 1,y+1}});
        if (node->right != NULL)
            que.push({node->right,{ x + 1,y+1}});
    }
    for (auto p: m) {
    	vector<int> col;
        for (auto q: p.second)
            {
            	col.insert(col.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(col);
        cout << endl;
    }

    return ans;
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
    vector<vector<int>> ans=printVerticalOrder(root);
    for(auto x:ans)
    {
    	for (auto p:x)
    	{
    		cout<<p<<"\t";
    	}
    	cout<<endl;
    }
}