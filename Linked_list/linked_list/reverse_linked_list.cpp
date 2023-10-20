/*
Given the head of a singly linked list, reverse the list, and return the reversed list.
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
*/
--------------------------------------------------------------------------------------------------------
Reverse Linked List: Iterative:	We will use three-pointers to traverse through the entire list and interchange links between nodes. 
One pointer to keep track of the current node in the list. The second one is to keep track of the previous node to the 
current node and change links. Lastly a pointer to keep track of nodes in front of current nodes.
STEP 1:
currrent_p is a pointer to keep track of current nodes. Set it to head.
prev_p is a pointer to keep track of previous nodes. Set it to NULL.
next_p is a pointer to keep track of the next nodes.
STEP 2:
Set next_p to point next node to node pointed by current_p.
Change link between nodes pointed by current_p and prev_p.
Update prev_p to current_p and current_p pointer to next_p.
Perform STEP 2 until current_p reaches the end of the list.
STEP 3:
Set head as prev_p. This makes the head point at the last node.	

ListNode* reverseList(ListNode* &head)
{
	ListNode *prev = NULL;
	ListNode *temp = NULL;
	ListNode *current = *head;
	while(current != NULL)
	{
		temp = current->next;
		current->next = prev;
		prev = current;
		current = temp;
	}
	*head = prev;
}
Time Complexity:
Since we are iterating only once through the list and achieving reversed list. Thus, the time complexity is O(N) where N is the number of nodes present in the list.
Space Complexity:
To perform given tasks, no external spaces are used except three-pointers. So, space complexity is O(1).
-------------------------------------------------------------------------------
Using Recursion:
 ListNode* reverseList(ListNode* &head) {

        if (head == NULL||head->next==NULL)
            return head;

        ListNode* nnode = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return nnode;
    }
Time Complexity:
We move to the end of the list and achieve our reversed list. Thus, the time complexity is O(N) where N represents the number of nodes.
Space Complexity:
Apart from recursion using stack space, no external storage is used. Thus, space complexity is O(1).

