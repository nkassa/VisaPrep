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
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        if(root == nullptr)
        {
            return {};
        }
        queue<TreeNode*> queue;
        queue.push(root);
        vector<vector<int>> ans;
        while(!queue.empty())
        {
            int size = queue.size();
            vector<int> curr;
            for(int i = 0; i < size; i++)
            {
                TreeNode* node = queue.front();
                queue.pop();
                curr.push_back(node->val);
                if(node->left)
                {
                    queue.push(node->left);
                }
                if(node->right)
                {
                    queue.push(node->right);
                }
            }
            ans.push_back(curr);
        }
        int left = 0;
        int right = ans.size()-1;
        while(left < right)
        {
            vector<int> temp = ans[left];
            ans[left] = ans[right];
            ans[right] = temp;
            left++;
            right--;
        }
        return ans;
    }
};