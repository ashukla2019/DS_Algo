//Rotate the linked list 
void rotate_list(ListNode** head, int k)
{
	if (k == 0)
        return;
 
    // Let us understand the below
    // code for example k = 4 and
    // list = 10->20->30->40->50->60.
    ListNode* current = *head;
 
    // Traverse till the end.
    while (current->next != NULL)
        current = current->next;
 
    current->next = *head;
    current = *head;
 
    // traverse the linked list to k-1 position which
    // will be last element for rotated array.
    for (int i = 0; i < k - 1; i++)
        current = current->next;
 
    // update the head_ref and last element pointer to NULL
    *head = current->next;
    current->next = NULL;
}
