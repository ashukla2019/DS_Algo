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
   if(root==NULL)
    return root;
    root->next = flatten(root->next);
    root=mergeList(root, root->next);
    return root;
}
