/*

Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

Example 1:
Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]

*/

ListNode* deleteDuplicates(ListNode* head) 
{
	if(!head || !head->next) return head;
	ListNode *next = head->next;
	
	if(next->val == head->val){
		while(next && next->val == head->val) next = next->next;
		return deleteDuplicates(next);
	} else {
		head->next = deleteDuplicates(next);
		return head;
	}
}