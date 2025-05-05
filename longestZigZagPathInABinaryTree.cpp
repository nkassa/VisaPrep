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
    int longestZigZag(TreeNode* root) 
    {
        if(root == nullptr)
        {
            return 0;
        }
        dfs(root, 0, 0);
        return ans;
    }
    // side == 0 means go left, and vice versa 
    void dfs(TreeNode* root, int side, int steps)
    {
        if(root == nullptr)
        {
            return;
        }
        ans = max(ans, steps);
        if(side == 0)
        {
            dfs(root->left, 0, 1);
            dfs(root->right, 1, steps+1);
        }
        else
        {
            dfs(root->left, 0, steps+1);
            dfs(root->right, 1, 1);
        }
    }
};