/*
//Flattening the linked list:
5 -> 10 -> 19 -> 28
|     |     |     | 
7     20    22   35
|           |     | 
8           50   40
|                 | 
30               45
Output:  5-> 7-> 8- > 10 -> 19-> 20->
22-> 28-> 30-> 35-> 40-> 45-> 50.
*/
ListNode* merge(ListNode* a, ListNode* b)
{    
    // If first linked list is empty 
    // then second is the answer
    if (a == NULL)
        return b;
  
    // If second linked list is empty 
    // then first is the result
    if (b == NULL)
        return a;
  
    // Compare the data members of the 
    // two linked lists and put the larger 
    // one in the result
    ListNode* result;
  
    if (a->val < b->val) 
    {
        result = a;
        //result->bottom = merge(a->bottom, b);
    }
  
    else 
    {
        result = b;
        //result->bottom = merge(a, b->bottom);
    }
    result->next = NULL;
    return result;
}
  
ListNode* flatten(ListNode* root)
{    
    // Base Cases
    if (root == NULL || root->next == NULL)
    {
        return root;
    }
    root->next = flatten(root->next);
    root = merge(root, root->next);
	return root;
}

//understand recursion used in flatten function():
//main()
//flatten(5)
//5->next = flatten(10)
//10->next = flatten(19)
//19->next = flatten(28)
//now since 28->next = null, recursion will stop here and root which has value 28 will be
//returned to caller(19->next = flatten(28)) => 19->next = 28
//will call merge(19, 28) and returned merged list will be assigned to root.
// root(19->head) will be assigned to next caller(10->next = flatten(19) => merged list with head 19
//merge(10,19) will be done now same way, merged returned list will be assigned to next caller
//(5->next = 10)....
