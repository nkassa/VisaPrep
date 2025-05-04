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
        ListNode* prev = new ListNode(0);
        prev->next = head;
        ListNode* ans = prev;
        ListNode* curr = head;
        int flag = 0;
        while(curr)
        {
            while(curr->next && curr->val == curr->next->val)
            {
                curr = curr->next;
                flag = 1;
            }
            if(flag == 1)
            {
                prev->next = curr->next;
                flag = 0;
            }
            else
            {
                prev = prev->next;
            }
            curr = curr->next;
        }
        return ans->next;
    }
};