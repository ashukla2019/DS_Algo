/*
Logic: 
1) Two pointer fast and slow. Fast will move two step and slow will move single step
until fast !=NULL && fast->next !=NULL
2) When fast or fast->next is null, we will retrun slow one as middle of linked list.

Time Complexity: O(n)
Space Complexity: O(1)

*/  
ListNode* middleNode(ListNode* head) 
    {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast !=NULL && fast->next !=NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
