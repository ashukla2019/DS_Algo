#include <iostream>
using namespace std;

struct node
{
    int data; //node will store an integer
    struct node *right_child; // right child
    struct node *left_child; // left child
};

struct node* search(struct node *root, int x)
{
    if(root==NULL || root->data==x) //if root->data is x then the element is found
        return root;
    else if(x>root->data) // x is greater, so we will search the right subtree
        return search(root->right_child, x);
    else //x is smaller than the data, so we will search the left subtree
        return search(root->left_child,x);
}

//function to create a node
struct node* new_node(int x)
{
    struct node *p;
    p = (struct node*)malloc(sizeof(struct node));
    p->data = x;
    p->left_child = NULL;
    p->right_child = NULL;

    return p;
}

struct node* insert(struct node *root, int x)
{
    //searching for the place to insert
    if(root==NULL)
        return new_node(x);
    else if(x>root->data) // x is greater. Should be inserted to right
        root->right_child = insert(root->right_child, x);
    else // x is smaller should be inserted to left
        root->left_child = insert(root->left_child,x);
    return root;
}

void pre_order_traversal(struct node* root) {
   if(root != NULL) {
      cout<<root->data<<endl;
      pre_order_traversal(root->left_child);
      pre_order_traversal(root->right_child);
   }
}

void inorder_traversal(struct node* root) {
   if(root != NULL) {
      inorder_traversal(root->left_child);
      cout<<root->data<<endl;         
      inorder_traversal(root->right_child);
   }
}

void post_order_traversal(struct node* root) {
   if(root != NULL) {
      post_order_traversal(root->left_child);
      post_order_traversal(root->right_child);
      cout<<root->data<<endl;
   }
}

int main() 
{
   struct node *root;
   root = new_node(20);
    insert(root,5);
    insert(root,1);
    insert(root,15);
    insert(root,9);
    insert(root,7);
    insert(root,12);
    insert(root,30);
    insert(root,25);
    insert(root,40);
    insert(root, 45);
    insert(root, 42);
   int i = 40;
   struct node * temp = search(root, i);

   if(temp != NULL) 
   {
      cout<<"Element found"<<temp->data<<endl;
     
   }
   else 
   {
      cout<<"Element not found"<<i<<endl;
   }

   cout<<"Preorder traversal"<<endl;
   pre_order_traversal(root);

   cout<<"Inorder traversal"<<endl;
   inorder_traversal(root);

   cout<<"Post order traversal"<<endl;
   post_order_traversal(root);       

   return 0;
}
