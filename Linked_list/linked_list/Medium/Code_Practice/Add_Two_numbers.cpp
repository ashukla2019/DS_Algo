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
