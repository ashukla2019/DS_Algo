/*
Palindrome: Check palindrome of linked list of numbers.
Given the head of a singly linked list, return true if it is a palindrome.
Input: head = [1,2,2,1]
Output: true
*/
bool isPalindrome(ListNode* head) 
{
	ListNode *node = head;
	string s;
	while(node)
	{
		int temp = node -> val;
		s += to_string(temp);
		node = node -> next;
	}

	string newS = string(s.rbegin(),s.rend());

	return s == newS ? true : false;
}
