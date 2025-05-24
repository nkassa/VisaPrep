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
        TreeNode* node = new TreeNode(0);
        TreeNode* ans = node;
        for(int num: list)
        {
            node->val = num;
            TreeNode* next = new TreeNode(0);
            node->right = next;
            node = node->right;
        }
        node = nullptr;
        return ans;
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