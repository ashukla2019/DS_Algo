1) Implement linkedlist:
class NodeList
{
public:
	int data;
	NodeList* next;
};

NodeList* addAtEnd(NodeList* head, int data)
{
	NodeList* temp = new NodeList();
	temp->data=data;
	temp->next=nullptr;
	if(head ==nullptr)
	{
		head = temp;
	}
	else
	{
		NodeList* t=head;
		while(t->next != nullptr)
		{
			t=t->next;
		}
		t->next=temp;
	}
	return head;
}

NodeList* addAtStart(NodeList* head, int data)
{
	NodeList* temp=new NodeList();
	temp->data=data;
	temp->next=head;
	head=temp;
	return head;
}

NodeList* deleteAtStart(NodeList* head)
{
	NodeList* temp=head;
	head=head->next;
	free(temp);
	return head;
}

Node* delete_data_end(Node* head)
{
	Node* temp;
	temp = head;
	while(temp->next->next !=nullptr)
	{
		temp = temp->next;
	}
	free(temp->next);
	temp->next = NULL;
	return head;
}

void printList(NodeList* head)
{
	NodeList* temp=head;
	cout<<"List-Nodes->";
	while(temp !=nullptr)
	{
		cout<<temp->data<< " ";
		temp=temp->next;
	}
	cout<<"\n";
}

NodeList* reverseList(NodeList* head)
{
    NodeList*current=head;
    NodeList* temp=nullptr;
    NodeList* prev=nullptr;
    while(current != nullptr)
    {
        temp = current->next;
        current->next=prev;
        prev=current;
        current=temp;
    }
    head=prev;
    return head;
}

int main()
{
	NodeList* head=nullptr;
	head = addAtEnd(head, 10);
	head = addAtEnd(head, 20);
	head = addAtStart(head, 5);
	printList(head);
	head = reverseList(head);
	printList(head);
	head = deleteAtStart(head);
	cout<<"After deleting from starting";
	printList(head);
	head = deleteAtEnd(head);
	cout<<"After deleting from End";
	printList(head);
	return 0;
}
------------------------------------------------------------------------------
2) Implement doubly linked list:
	class Node
{
	public:
		int data;
		Node* next;
		Node* prev;
};
	
Node* add_data_end(Node* head, int data)
{
	Node *temp = new Node();
	temp->data = data;
	temp->next = NULL;
	if(NULL == head)
	{
		head = temp;
		temp->prev = nullptr;
	}
	else
	{
		Node* t = head;
		while(t->next != nullptr)
		{
			t = t->next;
		}
		t->next = temp;
		temp->prev = t;
	}
	return head;
}

Node* delete_data_end(Node* head)
{
	Node* temp;
	temp = head;
	while(temp->next->next !=nullptr)
	{
		temp = temp->next;
	}
	free(temp->next);
	free(temp->next->prev);
	temp->next = NULL;
	return head;
}

Node* add_data_beg(Node* head, int item)
{
	Node* temp = new Node();
	temp->data = item;
	temp->next = head;
	head->prev = temp;
	head = temp;
	
	return head;
}

Node* delete_data_beg(Node* head)
{
	Node* temp;
	temp = head;
	head = temp->next;
	head->prev = nullptr;
	free(temp);
	
	return head;
	
}

Node* reverse_list(Node* head)
{
	Node *temp = NULL;
	Node *current = head;
	while(current != NULL)
	{
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = current->prev;
	}
	head = temp->prev;
	return head;
}
void show_data(Node* head)
{
	Node *temp;
	temp = head;
	while(temp !=NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<"\n";
}

int main(int argc, char* argv[])
{
	Node* head = nullptr; 
	head = add_data_end(head,10);
	head = add_data_end(head,20);
	show_data(head);
	head = reverse_list(head);
	cout<<"After reversing:"<<endl;
	show_data(head);
	head = add_data_beg(head, 5);	
	cout<<"After adding at begin"<<endl;
	show_data(head);
	head = delete_data_beg(head);
	cout<<"After deleting at begin"<<endl;
	show_data(head);
	head = delete_data_end(head);
	cout<<"After deleting at end"<<endl;
	show_data(head);
	head = add_data_end(head,30);
	cout<<"After deleting at end"<<endl;
	show_data(head);
	return 0;
}
------------------------------------------------------------------------------
3) Implement circular linked list:
class node
{
public:
    int data;
    node* next;
};
 
class clist
{
    node* last;
public:
    clist():last(nullptr) {}
    void addAtEnd(int data)
    {
        node* temp = new node();
        temp->data = data;
        //If it's first node we are gonna insert in circular linked list
        if (last == nullptr)
        {
            last = temp;
            temp->next = last;
        }
        else
        {
            //store last->next(first node) to temp->next
            //last->next should have address of temp
            //move last to temp
            temp->next = last->next;
            last->next = temp;
            last = temp;
        }
    }

    void addAtBeg(int data)
    {
        //assume(last->next means head)
        node* temp = new node();
        temp->data = data;
        temp->next = last->next; 
        last->next = temp;
    }

    void delete_data_beg()
    {
            node* temp = last->next;
            last->next = temp->next;
            temp->next = nullptr;
            free(temp);

    }
    
       
    void display()
    {
        node* temp = last->next;
        do
        {
            cout <<temp->data<<" ";
            temp = temp->next;
        } while (temp != last->next);
        cout<<"\n";
        
    }
};

int main()
{
    clist cl;
    cl.addAtEnd(10);
    cl.addAtEnd(20);
    cl.addAtEnd(30);
    cl.addAtEnd(40);
    cl.addAtBeg(5);
    cl.display();
    return 0;
}
-----------------------------------------------------------------------------------
4) Add two numbers in linked list:
Problem: You are given two non-empty linked lists representing two non-negative integers. The digits are
stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return 
the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

        2---->4---->3
        5---->6---->4
result= 7---->0---->8    

/*
1) Create dummy node with val 0
2) Set result to dummy
3) while(l1 !=NULL || l2 != NULL || carry !=0), do sum by adding
l1->val then l2->val and then carry;
4) Calculate carry by sum/10
5) Calculate node_value by (sum%10) and create new node and move result to next

*/  
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* dummy= new ListNode(0);
        ListNode* result=dummy;
        
        int carry=0;
        while(l1 !=NULL || l2 != NULL || carry !=0)
        {
            int sum=0;
            if(l1 != NULL)
            {
                sum=sum+l1->val;
                l1 = l1->next;
            }
             if(l2 != NULL)
            {
                sum=sum+l2->val;
                l2 = l2->next;
            }
            sum=sum+carry;
            carry=sum/10;
            result->next=new ListNode(sum%10);
            result=result->next;
        }
        return dummy->next;
    }
	TC-> O(max(l1, l2)
	SC-> O(max(l1,l2)
------------------------------------------------------------------------------
5) Odd & Even Linked list: You are given the 'head' of a singly linked list. Your task is to group 
all the nodes with odd indices together followed by the nodes with even indices, and return the 
reordered list’s head. The first node is considered odd, and the second node is even, and so on.
Example:
Input: 'head' -> 1 -> 3 -> 5 -> 7
Output: 'head' -> 1 -> 5 -> 3 -> 7
Explanation:
The nodes with odd indices (1, 5) are grouped together, followed by the nodes with even indices (3, 7).

Node* oddEvenList(Node* head)
{
	//Check if there is no node or only single node, then return head itself
	if(head==NULL || head->next==NULL) return head;
    Node * odd = head; //This will to link odd indices
    Node * even = head->next; //This will to link even indices
    Node * evenhead = even; //This would be required to link odd with even set of indices
    while(even && even->next){
        odd->next=odd->next->next; //odd pointer was pointing to 1st pos and now it's next is set to 3rd pos
        even->next=even->next->next; //even pointer was pointing to 2nd pos and now it's next is set to 4th pos
        odd=odd->next; //moving odd pointer to next which is 3rd...5th..7th....pos
        even=even->next; //moving even pointer to next which is 2nd...4th..6th....pos
    }
    odd->next = evenhead; //Now we have completed linking of odd nodes and even nodes, now set odd->next to evenhead(2nd pos)
    return head;
}
TC-> O(n) While loop is running n/2 times. 
SC-> O(1)
---------------------------------------------------------------------------------------
6) Sort linked list of 0s 1s 2s:
Given a linked list of 'N' nodes, where each node has an integer value that can be 0, 1, or 2. 
You need to sort the linked list in non-decreasing order and the return the head of the sorted list.
Example:
Given linked list is 1 -> 0 -> 2 -> 1 -> 2. 
The sorted list for the given linked list will be 0 -> 1 -> 1 -> 2 -> 2.

Approach: To store every type of value{0,1,2}, we need 3 dummy pointers for 0,1,2 series and head for all 
three would be required, we will take one more temp pointer to traverse complete list.
if temp->data =0 then zero->next=temp, elsif temp->data =1 then one->next=temp else two->next=temp

Node* sortList(Node *head){
    Node *zeroHead=new Node(-1);
    Node *oneHead=new Node(-1);
    Node *twoHead=new Node(-1);
    Node *zero=zeroHead;
    Node *one=oneHead;
    Node *two=twoHead;
    Node *temp=head;

    while(temp!=NULL){
        if(temp->data==0){
            zero->next=temp;
            zero=zero->next;
        }else if(temp->data==1){
            one->next=temp;
            one=one->next;
        }else{
            two->next=temp;
            two=two->next;
        }
        temp=temp->next;
    }
    zero->next=(oneHead->next)?(oneHead->next):(twoHead->next);
    one->next=twoHead->next;
    two->next=NULL;

    Node *newHead=zeroHead->next;
    //this is for more optimization , code can run without them also
    free(zeroHead);
    free(oneHead);
    free(twoHead);
    return newHead;
}
TC->O(n)
SC->O(1)
---------------------------------------------------------------------------------	
7) Remove Nth Node from the end of the LinkedList:
You have been given a singly Linked List of 'N' nodes with integer data and an integer 'K'.
Your task is to remove the 'K'th node from the end of the given Linked List and return the head 
of the modified linked list.
Example:
Input : 1 -> 2 -> 3 -> 4 -> 'NULL'  and  'K' = 2
Output: 1 -> 2 -> 4 -> 'NULL'

Approach: We will take two pointers fast and slow. Fast will move till kth position. we will chck
if fast==NULL then will return head->next

Node* removeKthNode(Node* head, int K)
{
    Node* fast =head;
    Node* slow = head;
    for(int i = 0; i<K; i++) 
    {
        fast = fast->next;
    }
    if (fast == NULL) 
    {
        return head->next;
    }
    while (fast->next != NULL) 
    {
        slow = slow->next;
        fast = fast->next;
    }
    Node* temp = slow->next;
    slow->next = slow->next->next;
    free(temp);
    return head;
}
TC->O(length)
SC->O(1)
---------------------------------------------------------------------------------
8) Reverse the linkedlist:
Input:
2 4 5 -1
Output:
5 4 2 -1
Approach1: Iterative way using 3 pointers
Node* reverse_list(Node* head)
{
	Node *temp = NULL;
	Node *current = head;
	while(current != NULL)
	{
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = current->prev;
	}
	head = temp->prev;
	return head;
}
TC->O(n)
SC->O(1)

Approach2: recursive approach
1->3->2->5->null
Node* reverseLinkedList(Node *head) 
{
   // Base case: If there is no node or only one node in list, return head...
   if(head==NULL||head->next==NULL)
	return head;
   
   Node *newhead=reverseLinkedList(head->next);
   Node *front=head->next;
   front->next=head;
   head->next=NULL;
   return newhead;
}
Dry Run:
//1->3->2->5 will be passed to head(head is pointing to 1) ->1st call
//3->2->5 will be passed to head(head is pointing to 3)-> 2nd call
//2->5 will be passed to head(head is pointing to 2) -->3rd call
//5 will be passed to head(head is pointing to 5) -->4th call
//Now base case will hit and head will be returned to previous call(3rd call)
newHead will start pointing to head returned from 4th call => newHead = 5(address of node having value 5) means newHead is 5 now
front = head->next(actual head was at 2(2->3)) now front will point to 5
front->next=head(5->next would be set to 2)==>links has been reversed
head->next=NULL ==> set 2->next to NULL 
Now list became:   NULL<-2<-5(newHead is at 5)
TC->O(n)
SC->O(n){auxiliary space}
------------------------------------------------------------------------------------
9) Check if a LinkedList is Palindrome or Not:
You are given a Singly Linked List of integers. You have to return true if the linked list is 
palindrome, else return false.
A Linked List is a palindrome if it reads the same from left to right and from right to left.
Example:
The lists (1 -> 2 -> 1), (3 -> 4 -> 4-> 3), and (1) are palindromes, while the lists (1 -> 2 -> 3) 
and (3 -> 4) are not.

Approach1: using stack data structure:
bool isPalindrome(Node* head)
{
	stack st;
	Node* temp = head;
	while(temp != NULL)
	{
		st.push(temp->data);
		temp = temp->next;
	}
	temp = head;
	while(temp != NULL)
	{
		if(temp->data != st.top())
			return false;
		temp = temp->next;
		st.pop();
	}
	return true;
}
TC-> O(n)
SC->O(n)

Approach 2: 
Find middle of list and then reverse 2nd half list
// Function to reverse a linked list
// using the recursive approach
Node* reverseLinkedList(Node* head) {
    // Check if the list is empty
    // or has only one node
    if (head == NULL || head->next == NULL) {
        
        // No change is needed;
        // return the current head
        return head; 
    }

    // Recursive step: Reverse the remaining 
    // part of the list and get the new head
    Node* newHead = reverseLinkedList(head->next);

    // Store the next node in 'front'
    // to reverse the link
    Node* front = head->next;

    // Update the 'next' pointer of 'front' to
    // point to the current head, effectively
    // reversing the link direction
    front->next = head;

    // Set the 'next' pointer of the
    // current head to 'null' to
    // break the original link
    head->next = NULL;

    // Return the new head obtained
    // from the recursion
    return newHead;
}

bool isPalindrome(Node* head) {
    // Check if the linked list is empty
    // or has only one node
    if (head == NULL || head->next == NULL) {
         // It's a palindrome by definition
        return true; 
    }
    // Initialize two pointers, slow and fast,
    // to find the middle of the linked list
    Node* slow = head;
    Node* fast = head;
    
    // Traverse the linked list to find the
    // middle using slow and fast pointers
    while (fast->next != NULL && fast->next->next != NULL) {
        // Move slow pointer one step at a time
        slow = slow->next;  
        // Move fast pointer two steps at a time
        fast = fast->next->next;  
    }
    
    // Reverse the second half of the
    // linked list starting from the middle
    Node* newHead = reverseLinkedList(slow->next);
    
    // Pointer to the first half
    Node* first = head;  
    
     // Pointer to the reversed second half
    Node* second = newHead; 
    while (second != NULL) {
        // Compare data values of 
        // nodes from both halves
        // If values do not match,
        // the list is not a palindrome
        if (first->data != second->data) {
            // Reverse the second half 
            // back to its original state
            reverseLinkedList(newHead);  
           // Not a palindrome
            return false;
        }
        // Move the first pointer
        first = first->next; 
        // Move the second pointer
        second = second->next;  
    }
    // Reverse the second half
    // back to its original state
    reverseLinkedList(newHead);  
    
    // The linked list is a palindrome
    return true;  
}
Time Complexity: O (2* N) The algorithm traverses the linked list twice, dividing it into halves
Space Complexity: O(1) 
-----------------------------------------------------------------------------------------
10) Add 1 to a number represented by LinkedList
You're given a positive integer represented in the form of a singly linked-list of digits. 
The length of the number is 'n'.
Add 1 to the number, i.e., increment the given number by one.
The digits are stored such that the most significant digit is at the head of the linked list and 
the least significant digit is at the tail of the linked list.
Ex1:
Input: Initial Linked List: 1 -> 5 -> 2
Output: Modified Linked List: 1 -> 5 -> 3
Ex2: 9->9 => 1->0->0




-------------------------------------------------------------------------------------------
11) Intersection of Two Linked Lists
4->1
	\
	 8
5->6/
Approach: l1 points to firsthead and l2 points to secondHead. Either of l1 or l2 is null return null
now check until l1!=l2(l1 and l2 will meet on intersection point or null)
if they meet then return l1 or l2. If any one becomes null then assign it to other list's head.

Node* findIntersection(Node *firstHead, Node *secondHead)
{
	Node* l1 = firstHead;
    Node* l2 = secondHead;
	
	//Base case
    if(l1 == NULL || l2 == NULL)
		return nullptr;

    while(l1 != l2){
        l1 = l1 -> next;
        l2 = l2 -> next;
        if(l1 == l2)
			return l2;
        if(l1 == NULL)
			l1 = secondHead;
        if(l2 == NULL)
			l2 = firstHead;
	}
    return l2;
}
TC->O(n1+n2)
SC->O(1)
------------------------------------------------------------------------------
12) Find the middle element of the LinkedList:
Given a singly linked list of 'N' nodes. The objective is to determine the middle node of a singly
linked list. However, if the list has an even number of nodes, we return the second middle node.
1 2 3 4 5 => 3 4 5(We can clearly see that there are 5 elements in the linked list therefore the middle node is the node with value '3'.)
Approach: Tortoise and hare algorithm
Node *findMiddle(Node *head) {
    Node* fast=head;
    Node* slow=head;
    while (fast != nullptr && fast->next != nullptr) {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
TC->O(n/2)
SC->O(1)
--------------------------------------------------------------------------
13) Detect a loop or cycle in LinkedList:
You are given a Singly Linked List of integers. Return true if it has a cycle, else return false.
1->2->3->4 
^        |
|        |  
--------- 
bool detectCycle(Node *head)
{
	Node* slow = head;
	Node* fast = head;
	while(fast!=NULL && fast->next!=NULL) //Incase of even and odd length of list, we should check both fast and fast->next
	{
		fast=fast->next->next;
		slow=slow->next;
		if(slow==fast) return true;
	}
	return false;
}
TC->O(n)
SC->O(1)
----------------------------------------------------------------------------
14) Find the length of loop in given linked list:
Input: Linked List: 4 -> 10 -> 3 -> 5 -> 10(at position 2)
Output: Length of cycle = 3
Explanation: The cycle is 10, 3, 5.

int findLength(Node* slow, Node* fast)
{
	int count=0;
	fast=head;
	while(slow != fast)
	{
		fast=fast->next;
		count++;
	}
	return count;
}

int lengthOfLoop(Node *head)
{
	Node* slow = head;
	Node* fast = head;
	while(fast!=NULL && fast->next!=NULL) //Incase of even and odd length of list, we should check both fast and fast->next
	{
		fast=fast->next->next;
		slow=slow->next;
		if(slow==fast) 
			return findLength(slow, fast);
	}
	return 0;
}
---------------------------------------------------------------------------
15) Delete the middle node of the LinkedList:
Given a singly linked list of 'N' nodes. Your task is to delete the middle node of this list
and return the head of the modified list.
However, if the list has an even number of nodes, we delete the second middle node
Example:
If given linked list is 1->2->3->4 then it should be modified to 1->2->4.
Node* deleteMiddle(Node* head)
{
	Node* fast=head;
    Node* slow=head;
	if(head==nullptr || head->next==nullptr)
		return null;
	fast = fast->next->next;  //this step is done so that slow moves one step less and once we complete, slow will be at mid-1.
    while (fast != nullptr && fast->next != nullptr) {
        slow=slow->next;
        fast=fast->next->next;
    }
    slow->next=slow->next->next;
	return head;
}
--------------------------------------------------------------------------------
16) Find the starting point of the Loop/Cycle in LinkedList 
You are given a singly linked list that may or may not contain a cycle. You are supposed to 
return the node where the cycle begins, if a cycle exists, else return 'NULL'.
A cycle occurs when a node's next pointer returns to a previous node in the list.
1 2 3 4 -1

Node* findLoopStartingPoint(Node *head)
{
	Node* slow = head;
	Node* fast = head;
	while(fast!=NULL && fast->next!=NULL) //Incase of even and odd length of list, we should check both fast and fast->next
	{
		fast=fast->next->next;
		slow=slow->next;
		if(slow==fast) 
		{
			slow = head;
			while(slow != fast)
			{
				slow=slow->next;
				fast=fast->next;
				
			}
			return slow;
		}
	}
	return NULL;
}
-----------------------------------------------------------------------------
17) Delete all occurances of key: A doubly-linked list is a data structure that consists of sequentially 
linked nodes, and the nodes have reference to both the previous and the next nodes in the sequence
of nodes. You’re given a doubly-linked list and a key 'k'.
Delete all the nodes having data equal to ‘k’.

Example:
Input: Linked List: 10 <-> 4 <-> 10 <-> 3 <-> 5 <-> 20 <-> 10 and ‘k’ = 10
Output: Modified Linked List: 4 <-> 3 <-> 5 <-> 20
Explanation: All the nodes having ‘data’ = 10 are removed from the linked list.

Node * deleteAllOccurrences(Node* head, int k) {
	Node *temp=head;

    while(temp != NULL) 
    {
		if (temp->data == k)
        {
			//If this is head of DLL, head will be updated post deletion
			if (temp == head) 
			{
				head=temp->next;
			}
			//Two pointers nextNode and prevNode are required to set linking(prev and next)
			Node* nextNode = temp->next;
			Node* prevNode = temp->prev;
			
			//Since, we are going to delete temp, will set nextNode->prev and prevNode->next correctly
			if(nextNode != NULL)
			{
				nextNode->prev=prevNode;
			}
			if(prevNode != NULL)
			{
				prevNode->next=nextNode;
			}
			free(temp);
			temp = nextNode;
		}
		else
		{
			temp = temp->next;
		}
	}
        
    return head;
}
--------------------------------------------------------------------------------
18) Merge two sorted linked list:
You are given two sorted linked lists. You have to merge them to produce a combined sorted linked list.
You need to return the head of the final linked list.
Note: The given linked lists may or may not be null.
For example:
If the first list is: 1 -> 4 -> 5 -> NULL and the second list is: 2 -> 3 -> 5 -> NULL
The final list would be: 1 -> 2 -> 3 -> 4 -> 5 -> 5 -> NULL

Node* sortTwoLinkedLists(Node* list1, Node* list2) {
    // Create a dummy node to serve
    // as the head of the merged list
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;

    // Traverse both lists simultaneously
    while (list1 != nullptr && list2 != nullptr) {
        // Compare elements of both lists and
        // link the smaller node to the merged list
        if (list1->data <= list2->data) {
            temp->next = list1; //temp->next is pointing to list1{dummy node(-1)->1)
			temp = list1; //Move temp to list1{temp is moved to node 1 of list1
            list1 = list1->next;
        } else {
            temp->next = list2;
			temp = list2;
            list2 = list2->next;
        }
        
    }

    // If any list still has remaining
    // elements, append them to the merged list
    if (list1 != nullptr) {
        temp->next = list1;
    } else {
        temp->next = list2;
    }
    // Return the merged list starting 
    // from the next of the dummy node
    return dummyNode->next;
}

//Understanding:
1 -> 4 -> 5 -> NULL
2 -> 3 -> 5 -> NULL
Merged-> dummy->1->2->3->4->5->5->NULL

Time Complexity: O(N1+N2) where N1 is the number of nodes in the first linked list and N1 in the second linked list as we traverse both linked lists in a single pass for merging without any additional loops or nested iterations.
Space Complexity : O(1) as no additional data structures or space is allocated for storing data, only a constant space for pointers to maintain for traversing the linked list.
-----------------------------------------------------------------------------------
19) Flattening a LinkedList:
3-->2->1-->4-->5             1
   10  7   9   6     =>      2
       11      8             3
	   12                    4 
	                         5
                             6
                             7
                             8
                             9
                             10
							 11
							 12
// Merges two linked lists in a particular
// order based on the data value
Node* merge(Node* list1, Node* list2){
    // Create a dummy node as a
    // placeholder for the result
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;

    // Merge the lists based on data values
    while(list1 != NULL && list2 != NULL){
        if(list1->data < list2->data){
            temp->child = list1; 
			temp = list1;
            list1 = list1->child;
        }
        else{
            temp->child = list2;
			temp = list2;
            list2 = list2->child;
        }
        temp->next=NULL; //For every added temp, next would be null
    }

    // Connect the remaining
    // elements if any
    if(list1){
        temp->child = list1;
    } else {
        temp->child = list2;
    }

    return dummyNode->child;
}

// Flattens a linked list with child pointers
Node* flattenLinkedList(Node* head) //flattenLinkedList(3)->flattenLinkedList(2/10)->flattenLinkedList(1/7/11/12)->flattenLinkedList(5/6/8)
{
    // If head is null or there 
    // is no next node, return head
    if(head == NULL || head->next == NULL){ //when list with head 5 is passed, 5->next would be null 
        return head; //Address of node with head 5 would be returned to call with head 4
    }

    // Recursively flatten the
    // rest of the linked list
    Node* nextHead = flattenLinkedList(head->next);
    head = merge(head, nextHead); //merge(4/9, 5/6/8) will be passed to merge function, new head after merge would be returned of merged list(4/5/6/8/9)
    return head;
}
--------------------------------------------------------------------------
20) Sort linkedlist using merged sort:
// Function to merge two sorted linked lists
Node* mergeTwoSortedLinkedLists(Node* list1, Node* list2) {
    // Create a dummy node to serve
    // as the head of the merged list
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;

    // Traverse both lists simultaneously
    while (list1 != nullptr && list2 != nullptr) {
        // Compare elements of both lists and
        // link the smaller node to the merged list
        if (list1->data <= list2->data) {
            temp->next = list1;
            list1 = list1->next;
        } else {
            temp->next = list2;
            list2 = list2->next;
        }
        // Move the temporary pointer
        // to the next node
        temp = temp->next; 
    }

    // If any list still has remaining
    // elements, append them to the merged list
    if (list1 != nullptr) {
        temp->next = list1;
    } else {
        temp->next = list2;
    }
    // Return the merged list starting 
    // from the next of the dummy node
    return dummyNode->next;
}

// Function to find the middle of a linked list
Node* findMiddle(Node* head){
    // If the list is empty or has only one node
    // the middle is the head itself
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // Initializing slow and fast pointers
    Node* slow = head;
    Node* fast = head->next;

    // Move the fast pointer twice as fast as the slow pointer
    // When the fast pointer reaches the end, the slow pointer
    // will be at the middle
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// Function to perform merge sort on a linked list
Node* sortLL(Node* head){
    // Base case: if the list is empty or has only one node
    // it is already sorted, so return the head
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    
    // Find the middle of the list using the findMiddle function
    Node* middle = findMiddle(head);
    
    // Divide the list into two halves
    Node* right = middle->next;
    middle->next = nullptr;
    Node* left = head;
    
    // Recursively sort the left and right halves
    left = sortLL(left);
    right = sortLL(right);
    
    // Merge the sorted halves using the mergeTwoSortedLinkedLists function
    return mergeTwoSortedLinkedLists(left, right);
}
3-->4-->2-->1-->5-->NULL								
	        / \	
3->4->2->NULL  1->5->NULL 
    /         \
   3->4->NULL  2->NULL	
  /     \       
3->NULL 4->NULL
-------------------------------------------------------------------------------
21) Remove duplicates from sorted DLL: 

