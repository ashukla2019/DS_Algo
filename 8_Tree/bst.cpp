#include<iostream>
#include<queue>
using namespace std;
class treeNode 
{
	public:
	int data;
	treeNode* left;
	treeNode* right;
};
//Function to find minimum in a tree. 
treeNode* FindMin(treeNode* root)
{
	while(root->left != NULL) 
	{
		root = root->left;
	}
	return root;
}

// Function to search a delete a value from tree.
treeNode* Delete(treeNode*root, int data)
{
	if(root == NULL)
	{		
		return root; 
	}
	else if(data < root->data)
	{
		root->left = Delete(root->left,data);
	}
	else if (data > root->data)
	{
		root->right = Delete(root->right,data);
	}
	else 
	{
		// Case 1:  No child
		if(root->left == NULL && root->right == NULL) 
		{ 
			delete root;
			root = NULL;
		}
		//Case 2: One child 
		else if(root->left == NULL) 
		{
			treeNode* temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL)
		{
			treeNode* temp = root;
			root = root->left;
			delete temp;
		}
		// case 3: 2 children
		else 
		{ 
			treeNode* temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right,temp->data);
		}
	}
	return root;
}
 
//Function to visit nodes in Inorder
void Inorder(treeNode* root)
{
	if(root == NULL)
	{
		return;
	}
 
	Inorder(root->left);       //Visit left subtree
	printf("%d ",root->data);  //Print data
	Inorder(root->right);      // Visit right subtree
}

//Function to visit nodes in Preorder
void Preorder(treeNode* root)
{
	if(root == NULL)
	{
		return;
	}
 
	//Visit left subtree
	printf("%d ",root->data);  //Print data
	Preorder(root->left);  
	Preorder(root->right);      // Visit right subtree
}

//Function to visit nodes in Postorder
void Postorder(treeNode* root)
{
	if(root == NULL)
	{
		return;
	}
 
	Postorder(root->left);       //Visit left subtree
	Postorder(root->right);      // Visit right subtree
	printf("%d ",root->data);    //Print data
}
 
// Function to Insert Node in a Binary Search Tree
treeNode* Insert(treeNode* root,char data)
{
	if(root == NULL) 
	{
		root = new treeNode();
		root->data = data;
		root->left = root->right = NULL;
	}
	else if(data <= root->data)
	{
		root->left = Insert(root->left,data);
	}
	else 
	{
		root->right = Insert(root->right,data);
	}
	return root;
}

//To search an element in BST, returns true if element is found
bool Search(treeNode* root,int data)
{
	if(root == NULL) 
	{
		return false;
	}
	else if(root->data == data) 
	{
		return true;
	}
	else if(data <= root->data) 
	{
		return Search(root->left,data);
	}
	else 
	{
		return Search(root->right,data);
	}
}

bool isValidBST(treeNode* root)
{
	return solve(root, INT_MIN, INT_MAX);
}

bool solve(treeNode* root, int minVal, int maxVal) {
	if (root == NULL) 
		return true;
	if (root->data >= maxVal || root->data <= minVal) 
		return false;
	return solve(root->left, minVal, root->data) && solve(root->right, root->data, maxVal);
}

treeNode* lowestCommonAncestor(treeNode* root, treeNode* p, treeNode* q) {
	//base case
	if (root == NULL || root == p || root == q) {
		return root;
	}
	treeNode* left = lowestCommonAncestor(root->left, p, q);
	treeNode* right = lowestCommonAncestor(root->right, p, q);

	//result
	if (left == NULL) {
		return right;
	}
	else if (right == NULL) {
		return left;
	}
	else { //both left and right are not null, we found our result
		return root;
	}
}



int main() 
{
	/*Code To Test the logic
	  Creating an example tree
	            5
			   / \
			  3   10
			 / \   \
			1   4   11
    */
	treeNode* root = NULL;
	root = Insert(root,5); root = Insert(root,10);
	root = Insert(root,3); root = Insert(root,4); 
	root = Insert(root,1); root = Insert(root,11);
	
	// Deleting node with value 5, change this value to test other cases
	//root = Delete(root,5);
	
	// Ask user to enter a number.  
	int number;
	cout<<"Enter number be searched\n";
	cin>>number;
	//If number is found, print "FOUND"
	if(Search(root,number) == true)
	{
		cout<<"Found\n";
	}
	else
	{
		cout<<"Not Found\n";
	}
	cout<<"Inorder: ";
	Inorder(root);
	cout<<"Preorder: ";
	Preorder(root);
	cout<<"Postorder: ";
	Postorder(root);
	cout<<"\n";
}