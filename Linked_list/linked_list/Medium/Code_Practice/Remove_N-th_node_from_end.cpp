Input:
N = 2
LinkedList: 1->2->3->4->5->6->7->8->9
Output: 8
Explanation: In the first example, there
are 9 nodes in linked list and we need
to find 2nd node from end. 2nd node
from end is 8.  
-----------------------------------------------------------------------------------------------
/*
1) Two pointers first and second will be set at head node
2) first will traverse n distance(1 to n), first will be ahead of second by n step
3) Check if first null, then return head->next
4) Now traverse first and second until first->next reaches to NULL
5) Now set second->next = second->next->next;
6) return head

*/  

ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode *fast = head, *slow = head;
        for (int i = 1; i <= n; i++) 
        {
            fast = fast->next;
        }
        if (!fast) 
            return head->next;
        while (fast->next)
        {   
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
