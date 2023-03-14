class Solution 
{
public:
    ListNode* reverseList(ListNode* head) 
    {
      // Iterative approach
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL)
        {
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
};
