Problem Statement: Given the heads of two singly linked-lists headA and headB, return the node at which
the two lists intersect. If the two linked lists have no intersection at all, return null.
Example 1:
Input:
List 1 = [1,3,1,2,4], List 2 = [3,2,4]
1-->3-->1-->2-->4
           /
          3
Output:
2
Explanation: Here, both lists intersecting nodes start from node 2.
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
