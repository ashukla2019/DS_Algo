5 -> 10 -> 19 -> 28
|     |     |     | 
7     20    22   35
|           |     | 
8          50    40
|                 | 
30               45
Output:  5-> 7-> 8- > 10 -> 19-> 20->
22-> 28-> 30-> 35-> 40-> 45-> 50.
Explanation:
The resultant linked lists has every 
node in a single level.
(Note: | represents the bottom pointer.)
 
Example 2:
Input:
5 -> 10 -> 19 -> 28
|          |                
7          22   
|          |                 
8          50 
|                           
30              
Output: 5->7->8->10->19->22->28->30->50
Explanation:
The resultant linked lists has every
node in a single level.
(Note: | represents the bottom pointer.)

Your Task:
You do not need to read input or print anything. Complete the function flatten() that takes the head of the linked list as input parameter and returns the head of flattened link list.

Expected Time Complexity: O(N*N*M)
Expected Auxiliary Space: O(N)

Constraints:
0 <= N <= 50
1 <= Mi <= 20
1 <= Element of linked list <= 103

--------------------------------------------------------------------------------------------
Node *mergeList(Node *l1, Node* l2)
{
   Node* result;    
   if(l1==NULL)
    return l2;
   
   if(l2==NULL)
    return l1;
    
   if(l1->data <= l2->data)
   {
       result=l1;
       result->bottom=mergeList(l1->bottom, l2);
   }
   else
   {
       result=l2;
       result->bottom=mergeList(l1, l2->bottom);
   }
   return result;
}

Node *flatten(Node *root)
{
   if(root==NULL || root->next==NULL)
    return root;
    root->next = flatten(root->next);
    root=mergeList(root, root->next);
    return root;
}
