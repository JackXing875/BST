#include <iostream>
#include <queue>

using namespace std;

typedef int datatype;

class TreeNode 
{
public:
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

    vector<int> preOrderTraversal(TreeNode* root) 
    {
        vector<int> res;

        if (root) 
        {
            res.push_back(root->val);

            vector<int> left = preOrderTraversal(root->left);
            res.insert(res.end(), left.begin(), left.end());

            vector<int> right = preOrderTraversal(root->right);
            res.insert(res.end(), right.begin(), right.end());
        }

        return res;
    }

    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> res;

        if (root) 
        {
            vector<int> left = inorderTraversal(root->left);
            res.insert(res.end(), left.begin(), left.end());

            res.push_back(root->val);

            vector<int> right = inorderTraversal(root->right);
            res.insert(res.end(), right.begin(), right.end());
        }

        return res;
    }

    vector<int> postOrderTraversal(TreeNode* root) 
    {
        vector<int> res;

        if (root) 
        {
            vector<int> left = postOrderTraversal(root->left);
            res.insert(res.end(), left.begin(), left.end());

            vector<int> right = postOrderTraversal(root->right);
            res.insert(res.end(), right.begin(), right.end());
            
            res.push_back(root->val);
        }

        return res;
    }

    vector<vector<int>> levelOrderTraversal(TreeNode* root) 
    {
        vector<vector<int>> res;

        if (!root) return res;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) 
        {
            vector<int> level;
            int levelSize = q.size();
            
            for(int i = 0; i < levelSize; i++) 
            {
                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            res.push_back(level);
        }

        return res;
    }
};
