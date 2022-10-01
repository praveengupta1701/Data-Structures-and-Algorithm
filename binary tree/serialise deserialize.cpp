#include <bits/stdc++.h>

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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        if(!root) return "";
        
        string s ="";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
           TreeNode* curNode = q.front();
           q.pop();
           if(curNode==NULL) s.append("#,");
           else s.append(to_string(curNode->val)+',');
           if(curNode != NULL){
               q.push(curNode->left);
               q.push(curNode->right);            
           }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL; 
        stringstream s(data);
        string str; 
        getline(s, str, ',');
        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode*> q; 
        q.push(root); 
        while(!q.empty()) {
            
            TreeNode *node = q.front(); 
            q.pop(); 
            
            getline(s, str, ',');
            if(str == "#") {
                node->left = NULL; 
            }
            else {
                TreeNode* leftNode = new TreeNode(stoi(str)); 
                node->left = leftNode; 
                q.push(leftNode); 
            }
            
            getline(s, str, ',');
            if(str == "#") {
                node->right = NULL; 
            }
            else {
                TreeNode* rightNode = new TreeNode(stoi(str)); 
                node->right = rightNode;
                q.push(rightNode); 
            }
        }
        return root; 
    }
     // Encodes a tree to a single string.
    void preorder(TreeNode * root,string & s){
        if(root == NULL){s+="#,";return;}
        s+=to_string(root->val);
        s+=",";
        preorder(root->left,s);
        preorder(root->right,s);
    }
    
    string serialize_pre(TreeNode* root) {
         if(root == NULL)
            return "";
        string s = "";
        preorder(root,s);
        return s;
    }

    // Decodes your encoded data to tree.
    
    TreeNode * cTree(string & data , int &index ){
        if(index == data.size())return NULL;
        int p = data.find(',',index);
        string temp = data.substr(index,p-index);
        index = p+1;
        if(temp=="#")return NULL;
        int val = stoll(temp);
        TreeNode * root = new TreeNode(val);
        root->left = cTree(data,index);
        root->right = cTree(data,index);
        return root;
    }
    
    TreeNode* deserialize_pre(string data) {
        int index = 0;
        return cTree(data,index);
        }
};
vector<vector<int>> levelorder(TreeNode* root)
{
    vector<vector<int>> ans;
    if(root==NULL)
    {
        return ans;
    }
    
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        int size =q.size();
        vector<int> level;
        for (int i = 0; i < size; ++i)
        {
            TreeNode* node=q.front();
            q.pop();
            if(node->left!=NULL) q.push(node->left);
            if(node->right!=NULL) q.push(node->right);
            level.push_back(node->val);
            cout<<node->val<<"\t";
        }
        ans.push_back(level);
        cout<<"\n";
    }
    return ans;

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
 root -> right -> left->left =new  TreeNode(15);
 root -> right -> right =new  TreeNode(8);

 Codec c;
 string s=c.serialize(root);
 cout<<"string :- "<<s<<"\n";
 TreeNode* ans=c.deserialize(s);
 levelorder(ans); 

}