Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the 
original list. Return the linked list sorted as well.
Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]

Input: head = [1,1,1,2,3]
Output: [2,3]  
 
ListNode* deleteDuplicates(ListNode* head) 
{
        ListNode* dummy = new ListNode(0, head);
        ListNode* pre = dummy;
        ListNode* cur = head;
        while (cur) 
        {
            while (cur->next && cur->next->val == cur->val) 
            {
                cur = cur->next;
            }
            if (pre->next == cur) //Means we have not duplicate nodes 
            {
                pre = cur;
            } 
            else  //Means we have duplicate nodes and need to set prev->next to correct place(after removing duplicates)
            {
                pre->next = cur->next;
            }
            cur = cur->next;
        }
        return dummy->next;
    }
