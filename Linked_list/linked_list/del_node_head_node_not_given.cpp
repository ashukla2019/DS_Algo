/*Delete Node in a Linked List, when head of linked list is not given.
Write a function to delete a node in a singly-linked list. You will not be given access to the head of the list, instead you will be given access to the node to be deleted directly.
Input: head = [4,5,1,9], node = 5
Output: [4,1,9]
Explanation: You are given the second node with value 5, the linked list should become 4 -> 1 -> 9 after calling your function.
approach: we can not go back, we will make current node(to be deleted) to next node 
and will delete next node.
*/
void deleteNode(ListNode* node) 
{
	node->val = node->next->val;
	node->next = node->next->next;
}
