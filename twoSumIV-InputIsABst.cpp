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
    bool findTarget(TreeNode* root, int k) 
    {
        dfs(root);
        int left = 0;
        int right = list.size()-1;
        while(left < right)
        {
            int sum = list[left] + list[right];
            if(sum > k)
            {
                right--;
            }
            else if(sum < k)
            {
                left++;
            }
            else
            {
                return true;
            }
        }
        return false;
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