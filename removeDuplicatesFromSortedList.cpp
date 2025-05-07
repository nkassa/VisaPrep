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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode* dummy = head;
        ListNode* ans = head;
        while(head)
        {
           while(head && dummy->val == head->val)
           {
                head = head->next;
           }
           dummy->next = head;
           dummy = dummy->next;
        }
        return ans;
    }
};