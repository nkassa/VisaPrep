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
    int ans = 0;
    int sumOfLeftLeaves(TreeNode* root) 
    {
        if(!root->left && ! root->right)
        {
            return 0;
        }
        dfs(root, 0);
        return ans;
    }
    void dfs(TreeNode* root, int leftSide)
    {
        if(!root)
        {
            return;
        }
        if(!root->left && ! root->right && leftSide == 0)
        {
            ans += root->val;
        }
        dfs(root->left, 0);
        dfs(root->right, 1);
    }
};