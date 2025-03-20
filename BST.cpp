#include <iostream>
#include <queue>

using namespace std;

typedef int datatype;

struct TreeNode 
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(datatype value) : val(value), left(nullptr), right(nullptr) {}
};

class BinaryTree 
{
public:
    TreeNode* root;

    BinaryTree() : root(nullptr) {}

    TreeNode* insert(TreeNode* root, datatype val) 
    {
        if (!root) return new TreeNode(val);
        if (val < root->val) root->left = insert(root->left, val);
        else root->right = insert(root->right, val);
        return root;
    }

    void preOrderTraversal(TreeNode* root) 
    {
        if (root) 
        {
            cout << root->val << " ";
            preOrderTraversal(root->left);
            preOrderTraversal(root->right);
        }
    }

    void inorderTraversal(TreeNode* root) 
    {
        if (root) 
        {
            inorderTraversal(root->left);
            cout << root->val << " ";
            inorderTraversal(root->right);
        }
    }

    void postOrderTraversal(TreeNode* root) 
    {
        if (root) 
        {
            postOrderTraversal(root->left);
            postOrderTraversal(root->right);
            cout << root->val << " ";
        }
    }

    void levelOrderTraversal(TreeNode* root) 
    {
        if (!root) return;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) 
        {
            TreeNode* node = q.front();
            q.pop();
            cout << node->val << " ";
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
};