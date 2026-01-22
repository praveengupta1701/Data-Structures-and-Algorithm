#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* findNode(TreeNode* root, int value) {
    if (root == NULL || root->val == value) {
        return root;
    }
    
    TreeNode* leftResult = findNode(root->left, value);
    if (leftResult != NULL) {
        return leftResult;
    }
    
    TreeNode* rightResult = findNode(root->right, value);
    if (rightResult != NULL) {
        return rightResult;
    }
    
    return NULL;
}

int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Search for nodes with specific values
    int targetValues[] = {1, 4, 7, 8};
    for (int i = 0; i < 4; i++) {
        TreeNode* result = findNode(root, targetValues[i]);
        if (result == NULL) {
            cout << "Node with value " << targetValues[i] << " not found" << endl;
        } else {
            cout << "Node with value " << targetValues[i] << " found" << endl;
        }
    }

    return 0;
}