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
    vector<int> list;
    void flatten(TreeNode* root) 
    {
        dfs(root);
        if(root)
        {
            root->val = list[0];
        }
        for(int i = 1; i < list.size(); i++)
        {
            if(root != nullptr)
            {
                root->left = nullptr;
                root->right = new TreeNode(list[i]);
                root = root->right;
            }
        }
    }
    void dfs(TreeNode* root)
    {
        if(root == nullptr)
        {
            return;
        }
        list.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
    }
};//