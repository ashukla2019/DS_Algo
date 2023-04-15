/*
Given the head of a singly linked list, reverse the list, and return the reversed list.
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
*/


void reverse_list(ListNode** head)
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
