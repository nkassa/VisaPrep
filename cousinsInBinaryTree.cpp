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
    bool isCousins(TreeNode* root, int x, int y) 
    {
        queue<TreeNode*> queue;
        queue.push(root);
        vector<vector<int>> lists;
        while(!queue.empty())
        {
            int size = queue.size();
            vector<int> list;
            for(int i = 0; i < size; i++)
            {
                TreeNode* node = queue.front();
                queue.pop();
                list.push_back(node->val);
                if(node->left)
                {
                    queue.push(node->left);
                }
                if(node->right)
                {
                    queue.push(node->right);
                }
            }
            lists.push_back(list);
        }
        for(int i = 0; i < lists.size(); i++)
        {
            bool xs = false;
            bool ys = false;
            for(int j = 0; j < lists[i].size(); j++)
            {
                if(lists[i][j] == x)
                {
                    xs = true;
                }
                if(lists[i][j] == y)
                {
                    ys = true;
                }
            }
            if(xs && ys)
            {
                return true;
            }
        }
        return false;
    }
};