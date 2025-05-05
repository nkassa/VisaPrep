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

    bool isSymmetric(TreeNode* root) 
    {
        if(root == nullptr)
        {
            return true;
        }
        return dfs(root->left, root->right);
    }
    bool dfs(TreeNode* leftSide, TreeNode* rightSide)
    {
        if(!leftSide && !rightSide)
        {
            return true;
        }
        if(!leftSide || !rightSide)
        {
            return false;
        }
        if(leftSide->val != rightSide->val)
        {
            return false;
        }
        return dfs(leftSide->left, rightSide->right) && dfs(leftSide->right, rightSide->left);
    }
};