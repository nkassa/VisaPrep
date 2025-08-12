class Solution {
  public:
    // Function to remove duplicates from sorted linked list.
    Node* removeDuplicates(Node* head) 
    {
        // code here
        Node* dummy = head;
        Node* ans = head;
        while(head)
        {
            while(head && dummy->data == head->data)
            {
                head = head->next;
            }
            dummy->next = head;
            dummy = dummy->next;
        }
        return ans;
    }
};