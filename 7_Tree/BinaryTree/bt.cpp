#include <iostream>
using namespace std;

class treeNode
{
public:
	int data;
	treeNode* left;
	treeNode* right;
};

treeNode* insert(int val)
{
	treeNode* temp = new treeNode();
	temp->data=val;
	temp->left=nullptr;
	temp->right=nullptr;
	return temp;	
}

void preorder(treeNode* root)
{
	if(root ==nullptr)
		return;
	cout<<root->data<<endl;
	preorder(root->left);
	preorder(root->right);
}

void inorder(treeNode* root)
{
	if(root ==nullptr)
		return;
	inorder(root->left);
	cout<<root->data<<endl;
	inorder(root->right);
}

void postorder(treeNode* root)
{
	if(root ==nullptr)
		return;
	
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<endl;
}

bool searchNode(treeNode* root, int key)
{
	if(root==nullptr)
		return false;
	if(root->data == key)
		return true;
		
	 /* then recur on left subtree */
    bool res1 = searchNode(root->left, key);
    // node found, no need to look further
    if(res1) 
    	return true; 
 
    /* node is not found in left, 
    so recur on right subtree */
    bool res2 = searchNode(root->right, key);
    if (res2) 
        return true;	
}

void printLeafNodes(treeNode* root)
{
    // if node is null, return
    if (root == nullptr)
        return;

    // if node is leaf node, print its data    
    if (root->left == nullptr && root->right == nullptr)
    {
        cout<<"leafnodes"<<root->data<<endl;
        return;
    }

    // if left child exists, check for leaf 
    // recursively
    printLeafNodes(root->left);

    // if right child exists, check for leaf 
    // recursively
    printLeafNodes(root->right);
}


int main()
{
	treeNode* root =insert(1);
	root->left = insert(2);
	root->right = insert(3);
	root->left->left = insert(4);
	root->right->left = insert(5);
	cout<<"-------------------preorder\n";
	preorder(root);
	cout<<"-------------------inorder\n";
	inorder(root);
	cout<<"-------------------postorder\n";
	postorder(root);
	cout<<"value is" <<searchNode(root, 12)<<endl;
	printLeafNodes(root);
	return 0;
}
