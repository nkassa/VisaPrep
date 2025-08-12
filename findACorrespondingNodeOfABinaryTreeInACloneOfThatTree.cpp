/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) 
    {
        if(!original || !cloned)
        {
            return nullptr;
        }
        if(original->val == cloned->val && original->val == target->val)
        {
            return cloned;
        }
        if(getTargetCopy(original->left, cloned->left, target))
        {
            return getTargetCopy(original->left, cloned->left, target);
        }
        return getTargetCopy(original->right, cloned->right, target);
    }
};