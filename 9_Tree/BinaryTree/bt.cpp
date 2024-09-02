#include <iostream>
#include <stack>
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
	temp->data = val;
	temp->left = nullptr;
	temp->right = nullptr;
	return temp;
}

void preorder(treeNode* root)
{
	if (root == nullptr)
		return;
	cout << root->data << endl;
	preorder(root->left);
	preorder(root->right);
}

void preorderIterative(treeNode* root)
{
	/*Approach: order is : Root, Left, Right
	1) Push root to stack
	2) Iterate stack until it is empty and print root
	3) Iterate throgh right subtree if available
	4) Iterate throgh left subtree if available
	*/
	stack<treeNode*> st;
	st.push(root);
	while (!st.empty())
	{
		root = st.top();
		cout << "node:" << root->data << endl;
		st.pop();

		if (root->right)
		{
			st.push(root->right);
		}
		if (root->left)
		{
			st.push(root->left);
		}
		
	}
}

void inorder(treeNode* root)
{
	if (root == nullptr)
		return;
	inorder(root->left);
	cout << root->data << endl;
	inorder(root->right);
}

void inorderIterative(treeNode* root)
{
	/*Approach: order is : Left, Root, Right
	1) Assign current node to root
	2) Iterate stack until it is empty and left subtree is not null
	3) Iterate throgh left subtree until it is null
	4) Pop the node and print it
	5) Iterate throgh right subtree if available
	*/
	stack<treeNode*>st;
	treeNode* current = root;
	while (!st.empty() || current != NULL)
	{
		if (current != nullptr)
		{
			st.push(current);
			current = current->left;
		}
		else
		{
			current = st.top();
			st.pop();
			current = current->right;
		}
	}
}

void postorder(treeNode* root)
{
	if (root == nullptr)
		return;

	postorder(root->left);
	postorder(root->right);
	cout << root->data << endl;
}

bool searchNode(treeNode* root, int key)
{
	if (root == nullptr)
		return false;
	if (root->data == key)
		return true;

	/* then recur on left subtree */
	bool res1 = searchNode(root->left, key);
	// node found, no need to look further
	if (res1)
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
		cout << "leafnodes" << root->data << endl;
		return;
	}

	// if left child exists, check for leaf 
	// recursively
	printLeafNodes(root->left);

	// if right child exists, check for leaf 
	// recursively
	printLeafNodes(root->right);
}

int height(treeNode* root)
{
	if (root == nullptr)
		return 0;
	int ltree = height(root->left);
	int rtree = height(root->right);
	return 1 + max(ltree, rtree);
}

//isbalancedBT:
int isbalanced(treeNode* root)
{
	if (root == NULL)
		return 0;
	int ltree = isbalanced(root->left);
	if (ltree == -1)
		return -1;
	int rtree = isbalanced(root->right);
	if (rtree == -1)
		return -1;
	if (abs(ltree - rtree) > 1)
		return -1;
	return 1+ max(ltree, rtree);

}
bool isbalancedBT(treeNode* root)
{
	return isbalanced(root)!=-1;
}

//Diameter:
int calculateDiameter(treeNode* root, int& diameter)
{
	if (root == NULL)
		return 0;
	int ltree = calculateDiameter(root->left, diameter);
	int rtree = calculateDiameter(root->right, diameter);
	
	diameter = max(diameter, ltree + rtree);
	return 1 + max(ltree, rtree);
}
int diameter(treeNode* root)
{
	int diameter = 0;
	calculateDiameter(root, diameter);
	return diameter;
}


void printLeftView(treeNode* root, int level)
{
	static int count = 0;
	if (root == NULL)
		return;
	if (count == level)
		cout << "Node=" << root->data << endl;
		count++;
	printLeftView(root->left, level+1);
	printLeftView(root->right, level + 1);

}

void leftView(treeNode* root)
{
	printLeftView(root, 0);
}


int main()
{
	treeNode* root = insert(1);
	root->left = insert(2);
	root->right = insert(3);
	root->left->left = insert(4);
	root->right->left = insert(5);
	cout << "-------------------preorder\n";
	preorder(root);
	cout << "-------------------inorder\n";
	inorder(root);
	cout << "-------------------postorder\n";
	postorder(root);
	cout << "value is" << searchNode(root, 12) << endl;
	printLeafNodes(root);
	int h = height(root);
	preorderIterative(root);
	inorderIterative(root);
	isbalancedBT(root);
	diameter(root);
	leftView(root);
	return 0;
}
