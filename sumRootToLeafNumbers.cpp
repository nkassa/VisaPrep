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
    vector<string> paths;
    int sumNumbers(TreeNode* root) 
    {
        string path = "";
        dfs(root, path);
        long int sum = 0;
        for(string path: paths)
        {
            long int digit = 1;
            for(int i = path.size()-1; i >= 0; i--)
            {
                sum += (digit * path[i]);
                digit *= 10;
            }
        }
        return sum;
    }
    void dfs(TreeNode* root, string path)
    {
        if(!root)
        {
            return;
        }
        path += root->val;
        if(!root->left && !root->right)
        {
            paths.push_back(path);
        }
        dfs(root->left, path);
        dfs(root->right, path);
    }
};