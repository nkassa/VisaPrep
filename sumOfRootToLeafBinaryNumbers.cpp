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
    vector<vector<int>> paths;
    int sumRootToLeaf(TreeNode* root) 
    {
        vector<int> path = {};
        dfs(root, path);
        int sum = 0;
        for(vector<int> list: paths)
        {
            int n = list.size();
            int digit = 0;
            for(int i = n-1; i >= 0; i--)
            {
                sum += list[i] * pow(2,digit);
                digit += 1;
            }
        }
        return sum;
    }
    void dfs(TreeNode* root, vector<int> path)
    {
        if(!root)
        {
            return;
        }
        path.push_back(root->val);
        if(!root->left && !root->right)
        {
            paths.push_back(path);
        }
        dfs(root->left, path);
        dfs(root->right, path);
    }
};