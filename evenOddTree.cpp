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
    bool isEvenOddTree(TreeNode* root) 
    {
        vector<vector<int>> lists;
        queue<TreeNode*> queue;
        queue.push(root);
        while(!queue.empty())
        {
            vector<int> list;
            int size = queue.size();
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
            if(i % 2 == 0)
            {
                for(int j = 0; j < lists[i].size(); j++)
                {
                    if(j != 0 && lists[i][j-1] >= lists[i][j])
                    {
                        return false;
                    }
                    if(lists[i][j] % 2 == 0)
                    {
                        return false;
                    }
                }
            }
            else
            {
                for(int j = lists[i].size()-1; j >= 0; j--)
                {
                    if(j != lists[i].size()-1 && lists[i][j+1] >= lists[i][j])
                    {
                        return false;
                    }
                    if(lists[i][j] % 2 != 0)
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};