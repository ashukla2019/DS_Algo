/*
1) Set d1 to headA and d2 to headB
2) Travese until d1 !=d2(d1 will meeto to d2 at intersection point or null)
3) update d1: if d1==NULL then set d1 to headB else d1=d1->next 
   update d2: if d2==NULL then set d2 to headB else d2=d2->next
4) Return d1(will be intersection point wether it is valid node or null)
*/


ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
       ListNode* d1 = headA;
       ListNode* d2 = headB;
    
    while(d1 != d2) 
    {
        d1 = d1 == NULL? headB:d1->next;
        d2 = d2 == NULL? headA:d2->next;
    }
    
    return d1;
    }
