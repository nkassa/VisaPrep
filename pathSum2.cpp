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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        vector<vector<int>> ans;
        vector<int> curr = {};
        dfs(root, ans, curr, targetSum);
        return ans;
    }
    void dfs(TreeNode* root, vector<vector<int>>& ans, vector<int> curr, int targetSum)
    {
        if(root == nullptr)
        {
            return;
        }
        curr.push_back(root->val);
        targetSum -= root->val;
        if(!root->left && !root->right && targetSum == 0)
        {
            ans.push_back(curr);
        }
        dfs(root->left, ans, curr, targetSum);
        dfs(root->right, ans, curr, targetSum);
    }
};