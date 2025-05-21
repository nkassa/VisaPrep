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
    int pathSum(TreeNode* root, int targetSum)
    {
        if(root == nullptr)
        {
            return 0;
        }
        dfs(root, targetSum);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
        return ans;
    }
    void dfs(TreeNode* root, long int targetSum)
    {
        if(root == nullptr)
        {
            return;
        }
        targetSum -= root->val;
        if(targetSum == 0)
        {
            ans++;
        }
        dfs(root->left, targetSum);
        dfs(root->right, targetSum);
    }
};