/*
1) Create result linked list
2) Check if any of list is empty/null then return other(if l1 empty then return l2, viceversa)
3) Check if list1->data <= list2->data then result should point to list1
   result->next=mergetwolist(list1->next, list2);
4) Check if list2->data <= list1->data then result should point to list2
   result->next=mergetwolist(list1, list2->next);
5) Return result

Time Complexity: O(n)
Space Complexity: O(n) -> we have used new linked list to store data.
 */ 

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode* result;
        if(list1 == NULL)
            return list2;
        if(list2 == NULL)
            return list1;
        if(list1->val <= list2->val)
        {
            result = list1;
            result->next = mergeTwoLists(list1->next, list2);
        }   
        else
        {
            result = list2;
            result->next = mergeTwoLists(list1, list2->next);
        } 
        return result;        
    }
