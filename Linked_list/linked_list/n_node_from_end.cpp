//Get the nth node from the end of linked list:
//difference b/w last node and nth node will be n-1. this difference can be covered first for
//first pointer and then difference b/w first and second will be n-1. then e can move
//both pointer one step and once first reaches last node, will find desired node pointed by second.
int getNthFromLast(ListNode* head, int k)
{
	ListNode* first = head;
	for(int i =1; i < k; i++)
	{
		first = first->next;
	}
	ListNode* second = head;
	while(first->next != nullptr)
	{
 		first = first->next;
		second = second->next;
	}
	return second->val;
}
