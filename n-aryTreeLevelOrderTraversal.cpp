/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) 
    {
        if(!root)
        {
            return {};
        }
        vector<vector<int>> ans;
        queue<Node*> queue;
        queue.push(root);
        while(!queue.empty())
        {
            int size = queue.size();
            vector<int> curr;
            for(int i = 0; i < size; i++)
            {
                Node* node = queue.front();
                queue.pop();
                curr.push_back(node->val);
                for(Node* child: node->children)
                {
                    queue.push(child);
                }
            }
            ans.push_back(curr);
        }
        return ans;
    }
};