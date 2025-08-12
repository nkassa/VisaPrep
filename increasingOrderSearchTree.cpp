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
    TreeNode* increasingBST(TreeNode* root) 
    {
        dfs(root);
        TreeNode* dummy = new TreeNode(0);
        TreeNode* ans = dummy;
        for(int i = 0; i < list.size(); i++)
        {
            TreeNode* node = new TreeNode(list[i]);
            dummy->right = node;
            dummy = dummy->right;
        }
        return ans->right;
    }
    void dfs(TreeNode* root)
    {
        if(!root)
        {
            return;
        }
        dfs(root->left);
        list.push_back(root->val);
        dfs(root->right);
    }
};