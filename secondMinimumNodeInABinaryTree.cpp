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
    unordered_set<int> seen;
    int findSecondMinimumValue(TreeNode* root) 
    {
        dfs(root);
        if(seen.size() < 2)
        {
            return -1;
        }
        priority_queue<int, vector<int>, greater<int>> heap;
        for(auto key: seen)
        {
            heap.push(key);
        }
        heap.pop();
        return heap.top();
    }
    void dfs(TreeNode* root)
    {
        if(!root)
        {
            return;
        }
        seen.insert(root->val);
        dfs(root->left);
        dfs(root->right);
    }
};