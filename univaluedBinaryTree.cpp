/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int value = 0;
    bool isUnivalTree(TreeNode* root) 
    {
        value = root->val;
        return dfs(root);
    }
    bool dfs(TreeNode* root)
    {
        if(!root)
        {
            return true;
        }
        if(value != root->val)
        {
            return false;
        }
        return dfs(root->left) && dfs(root->right);
    }
};