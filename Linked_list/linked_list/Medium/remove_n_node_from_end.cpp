//Get the nth node from the end of linked list:
//difference b/w last node and nth node will be n-1. this difference can be covered first for
//first pointer and then difference b/w first and second will be n-1. then e can move
//both pointer one step and once first reaches last node, will find desired node pointed by second.
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
--------------------------------------------------------------------------------------------------------	
Solution 1: Naive Approach [Traverse 2 times]
Intuition: We can traverse through the Linked List while maintaining a count of nodes, let’s say in the variable count, 
and then traversing for the 2nd time for (n – count) nodes to get to the nth node of the list.

Solution 2: [Efficient] Two pointer Approach
Unlike the above approach, we don’t have to maintain the count value, we can find the nth node just by one traversal 
by using two pointer approach.

ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * start = new ListNode();
        start -> next = head;
        ListNode* fast = start;
        ListNode* slow = start;     

        for(int i = 1; i <= n; ++i)
            fast = fast->next;
    
        while(fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        
        slow->next = slow->next->next;
        
        return start->next;
    }
Time Complexity: O(N)
Space Complexity: O(1)
