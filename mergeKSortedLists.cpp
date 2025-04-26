/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        priority_queue<int, vector<int>, greater<int>> heap;
        for(int i = 0; i < lists.size(); i++)
        {
            ListNode* node = lists[i];
            while(node)
            {
                heap.push(node->val);
                node = node->next;
            }
        }
        ListNode* ans = new ListNode(0);
        ListNode* curr = ans;
        while(!heap.empty())
        {
            curr->next = new ListNode(heap.top());
            heap.pop();
            curr = curr->next;
        }
        return ans->next;
    }
};