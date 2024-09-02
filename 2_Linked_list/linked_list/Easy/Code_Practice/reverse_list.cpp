list: 1-->2-->3-->4
reverse: 1<--2<--3<--4  

/*
We will take 3 pointers:
  1)current will point to head
  2)temp to hold the current->next, so that we can move ahead and current can follow to it
  3)prev: it will be used to store current->next
 Logic: 
 we have to traverse current until it becomes null, and follow below steps:
 1) Put temp into current->next(temp=current->next)
 2) Now reverse current->next link by putting prev to current->next
 3) Now move prev to current and current to temp
 4) Once current is null, put header to prev node.

Time complexity:O(n)
Space complexity: O(1)
*/
  
ListNode* reverseList(ListNode* head) 
    {
        ListNode* current=head;
        ListNode* prev=NULL;
        ListNode* temp;
        while(current !=NULL)
        {
            temp = current->next;
            current->next=prev;
            prev=current;
            current=temp;
        }
        head=prev;
        return head;
    }
