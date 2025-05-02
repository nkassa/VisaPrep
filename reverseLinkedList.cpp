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
    /*
        prev = prev node
        head = curr node
        next = makes sure you still have access to rest of original linked list 
    */
    ListNode* reverseList(ListNode* head) 
    {
        ListNode* prev = nullptr;
        // while the current linkedlist is not a nullptr, flip the point the opp. direction
        while(head != nullptr)
        {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        // return new head of linkedlist 
        return prev;
    }
};