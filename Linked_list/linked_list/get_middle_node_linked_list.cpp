/*Get middle node of linked list: Time complexity o(n/2) because we traverse only half nodes => o(n)
//tortoise and hare approach: Hare will move 2 steps and tortoise will move 1 step.
Given the head of a singly linked list, return the middle node of the linked list.
If there are two middle nodes, return the second middle node.
Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.
*/
int getMiddle(ListNode *head)
{
	 if(head==nullptr){
		return 0;
	}
	ListNode* fast=head;
	ListNode*slow=head;
	while(fast!=nullptr && fast->next!=nullptr){
		slow=slow->next;
		fast=fast->next->next;
	}
	return slow->val;

}
