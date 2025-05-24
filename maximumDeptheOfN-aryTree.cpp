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
    int maxDepth(Node* root) 
    {
        if(!root)
        {
            return 0;
        }
        queue<Node*> queue;
        queue.push(root);
        int ans;
        while(!queue.empty())
        {
            int size = queue.size();
            ans++;
            for(int i = 0; i < size; i++)
            {
                Node* node = queue.front();
                queue.pop();
                for(Node* next: node->children)
                {
                    queue.push(next);
                }
            }
        }
        return ans;
    }
};