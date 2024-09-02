/*Get middle node of linked list: Time complexity o(n/2) because we traverse only half nodes => o(n)
//tortoise and hare approach: Hare will move 2 steps and tortoise will move 1 step.
Given the head of a singly linked list, return the middle node of the linked list.
If there are two middle nodes, return the second middle node.
Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.
*/
-------------------------------------------------------------------------------------------
Solution 1: Naive Approach
Intuition: We can traverse through the Linked List while maintaining a count of nodes let’s say in variable n, and then
traversing for 2nd time for n/2 nodes to get to the middle of the list.	
ListNode* middleNode(ListNode* head) {
    	int n = 0;
    	ListNode* temp = head;
    	while(temp) {
        	n++;
        		temp = temp->next;
    	}
   	 
    	temp = head;
   	 
    	for(int i = 0; i < n / 2; i++) {
        		temp = temp->next;
    	}
   	 
    	return temp;
	}
---------------------------------------------------------------------------------------------
Solution 2: [Efficient] Tortoise-Hare-Approach
Unlike the above approach, we don’t have to maintain node count here and we will be able to find the middle node in a single traversal so this approach is more efficient.
Intuition: In the Tortoise-Hare approach, we increment slow ptr by 1 and fast ptr by 2, so if take a close look fast ptr will travel double that of the slow pointer. So when the fast ptr will be at the end of the Linked List, slow ptr would have covered half of the Linked List till then. So slow ptr will be pointing towards the middle of Linked List.
Approach: 
Create two pointers slow and fast and initialize them to a head pointer.
Move slow ptr by one step and simultaneously fast ptr by two steps until fast ptr is NULL or next of fast ptr is NULL.
When the above condition is met, we can see that the slow ptr is pointing towards the middle of the Linked List and hence we can return the slow pointer.

ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next)
            slow = slow->next, fast = fast->next->next;
        return slow;
    }
Time Complexity: O(N)
Space Complexity: O(1)	
