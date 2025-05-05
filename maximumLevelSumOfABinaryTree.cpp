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
    int maxi = INT_MIN;
    int ans = 0;
    int maxLevelSum(TreeNode* root) 
    {
        queue<TreeNode*> queue;
        queue.push(root);
        int level = 0;
        while(!queue.empty())
        {
            level++;
            int sum = 0;
            int size = queue.size();
            for(int i = 0; i < size; i++)
            {
                TreeNode* node = queue.front();
                sum += node->val;
                queue.pop();
                if(node->left)
                {
                    queue.push(node->left);
                }
                if(node->right)
                {
                    queue.push(node->right);
                }
            }
            if(maxi < sum)
            {
                maxi = sum;
                ans = level;
            }
        }
        return ans;
    }
};