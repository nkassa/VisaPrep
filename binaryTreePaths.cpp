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
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        string path = "";
        dfs(root, path);
        for(int i = 0; i < paths.size(); i++)
        {
            paths[i].pop_back();
            paths[i].pop_back();
        }
        return paths;
    }
    void dfs(TreeNode* root, string path)
    {
        if(!root)
        {
            return;
        }
        path += to_string(root->val);
        path += "->";
        if(!root->left && !root->right)
        {
            paths.push_back(path);
        }
        dfs(root->left, path);
        dfs(root->right, path);
    }
};