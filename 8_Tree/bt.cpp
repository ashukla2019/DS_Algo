#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>

using namespace std;

class treeNode
{
public:
	int data;
	treeNode* left;
	treeNode* right;
	treeNode() = default;
	treeNode(int data):data(data)
	{}
};

treeNode* addNode(treeNode* root, int data)
{
	treeNode* temp = new treeNode();
	temp->data = data;
	temp->left = nullptr;
	temp->right = nullptr;
	return temp;
	
}

void preOrderTraversalRecursive(treeNode* root)
{
	//Base case:
	if (root == nullptr)
		return;
	cout << "Node:" << root->data << endl;
	preOrderTraversalRecursive(root->left);
	preOrderTraversalRecursive(root->right);
}

void inOrderTraversalRecursive(treeNode* root)
{
	//Base case:
	if (root == nullptr)
		return;
	inOrderTraversalRecursive(root->left);
	cout << "Node:" << root->data << endl;
	inOrderTraversalRecursive(root->right);
}

void postOrderTraversalRecursive(treeNode* root)
{
	//Base case:
	if (root == nullptr)
		return;
	postOrderTraversalRecursive(root->left);
	postOrderTraversalRecursive(root->right);
	cout << "Node:" << root->data << endl;
}

void preOrdertraversalIterative(treeNode* root)
{
	//We need stack to store the traversed nodes:
	stack<treeNode*>st;
	st.push(root);
	while (!st.empty())
	{
		treeNode* temp = st.top();
		cout << "Node=" << temp->data << endl;
		st.pop();

		//Check the left and right child , if not null then push them into stack
		if (temp->right)
			st.push(temp->right);
		if (temp->left)
			st.push(temp->left);
	}
}

void inOrdertraversalIterative(treeNode* root)
{
	//We need stack to store the traversed nodes:
	stack<treeNode*>st;
	//Required to traverse the left subtree and when left subtree is null then will print them out
	//then right subtree will be visited
	treeNode* current = root;

	while (current || !st.empty())
	{
		//While left subtree is available
		while (current)
		{
			st.push(current);
			current = current->left;
		}
		//left subtree is null:
		current = st.top();
		st.pop();
		cout << "Node:" << current->data << endl;
		current = current->right;

	}
}

bool searchInBinaryTree(treeNode* root, int val)
{
	//If root is null then data will not be found
	if (root == nullptr)
		return false;
	if (root->data == val)
		return true;
	//traverse left subtree:
	int lt = searchInBinaryTree(root->left, val);
	if (lt == true)
		return true;
	//traverse right subtree:
	int rt = searchInBinaryTree(root->right, val);
	if (rt == true)
		return true;
}

int maxDepthBT(treeNode* root)
{
	//Base case:
	if (root == nullptr)
		return 0;
	
	int lt = maxDepthBT(root->left);
	int rt = maxDepthBT(root->right);
	return 1 + max(lt, rt);

}

int calculateDiameter(treeNode* root, int& diameter)
{
	if (root == nullptr)
		return 0;

	int lt = calculateDiameter(root->left, diameter);
	int rt = calculateDiameter(root->right, diameter);

	//Update Diameter:
	diameter = max(diameter, lt + rt);

	return 1 + max(lt, rt);
}
int diameterOfBT(treeNode* root)
{
	int diameter = 0;
	calculateDiameter(root, diameter);
	return diameter;
}

//print Left View of Binary tree
void checkLeftView(treeNode* root, vector<int>& ltNodes, int level)
{
	//Base case:
	if (root == nullptr)
		return;
	//If level == ltNodes.size() => means we are considering first node from every level
	if (ltNodes.size() == level)
	{
		ltNodes.push_back(root->data);
	}
	checkLeftView(root->left, ltNodes, level + 1);
	checkLeftView(root->right, ltNodes, level + 1);
}

void leftView(treeNode* root)
{
	//vector to store nodes at left view
	vector<int>ltNodes;
	//passing level=0 for root node:
	checkLeftView(root, ltNodes, 0);
	for (auto it : ltNodes)
	{
		cout << "Nodes at left side:" << it << endl;
	}
}

//print Right View of Binary tree
void checkRightView(treeNode* root, vector<int>& rtNodes, int level)
{
	//Base case:
	if (root == nullptr)
		return;
	//If level == ltNodes.size() => means we are considering first node from every level
	if (rtNodes.size() == level)
	{
		rtNodes.push_back(root->data);
	}
	checkRightView(root->right, rtNodes, level + 1);
	checkRightView(root->left, rtNodes, level + 1);
}

void rightView(treeNode* root)
{
	//vector to store nodes at left view
	vector<int>rtNodes;
	//passing level=0 for root node:
	checkRightView(root, rtNodes, 0);
	for (auto it : rtNodes)
	{
		cout << "Nodes at right side:" << it << endl;
	}
}

vector<vector<int>> levelOrderTraversal(treeNode* root)
{
	queue<treeNode*>q;
	q.push(root);
	//To store answer of traversal:
	vector<vector<int >> ans;
	
	while (!q.empty())
	{	
		int size = q.size();
		vector<int>levelOrderTraverse;
		for (int i = 0; i < size; i++)
		{
			root = q.front();
			levelOrderTraverse.push_back(root->data);
			q.pop();

			//Check lfet and right children:
			if (root->left)
				q.push(root->left);
			if (root->right)
				q.push(root->right);
		}
		ans.push_back(levelOrderTraverse);
	}
	return ans;
	
}

vector<vector<int>> zigzagTraversal(treeNode* root)
{
	queue<treeNode*>q;
	q.push(root);
	//To store answer of traversal:
	vector<vector<int >> ans;
	bool isLeftToRight = true;
	while (!q.empty())
	{
		int size = q.size();
		vector<int>zigZagTraverse(size);
		
		for (int i = 0; i < size; i++)
		{
			root = q.front();
			//Check isLeftToRight is true:
			int index = isLeftToRight ? i : size-1-i;
			zigZagTraverse[index] = root->data;
			q.pop();

			//Check lfet and right children:
			if (root->left)
				q.push(root->left);
			if (root->right)
				q.push(root->right);
		}
		//Set isLeftToRight reverese.
		isLeftToRight = !isLeftToRight;
		ans.push_back(zigZagTraverse);
	}
	return ans;

}

// Function to return the top view of a binary tree
vector<int> topView(treeNode* root) {
	vector<int> result;
	if (!root) return result;

	// Map to store the first node at each 
	  // vertical distance (vd)
	map<int, int> topNodes;

	// Queue to store nodes along with their
	// vertical distance
	queue<pair<treeNode*, int>> q;

	// Start BFS with the root node at 
	// horizontal distance 0
	q.push({ root, 0 });

	while (!q.empty()) {

		auto nodeVd = q.front();

		// Current node
		treeNode* node = nodeVd.first;

		// Current horizontal distance
		int hd = nodeVd.second;
		q.pop();

		// If this horizontal distance is seen for the first
		  // time, store the node
		if (topNodes.find(hd) == topNodes.end()) {
			topNodes[hd] = node->data;
		}

		// Add left child to the queue with horizontal
		  // distance - 1
		if (node->left) {
			q.push({ node->left, hd - 1 });
		}

		// Add right child to the queue with 
		// horizontal distance + 1
		if (node->right) {
			q.push({ node->right, hd + 1 });
		}
	}

	// Extract the nodes from the map in sorted order 
	  // of their horizontal distances
	for (auto it : topNodes) {
		result.push_back(it.second);
	}

	return result;
}

// Function to return the top view of a binary tree
vector<int> bottomView(treeNode* root) {
	vector<int> result;
	if (!root) return result;

	// Map to store the first node at each 
	  // horizontal distance (hd)
	map<int, int> bottomNodes;

	// Queue to store nodes along with their
	// horizontal distance
	queue<pair<treeNode*, int>> q;

	// Start BFS with the root node at 
	// horizontal distance 0
	q.push({ root, 0 });

	while (!q.empty()) {

		auto nodeHd = q.front();

		// Current node
		treeNode* node = nodeHd.first;

		// Current horizontal distance
		int hd = nodeHd.second;
		q.pop();

		//No need to check if line or level traveresed, since it will be overwritten for bottomView
		bottomNodes[hd] = node->data;
		

		// Add left child to the queue with horizontal
		  // distance - 1
		if (node->left) {
			q.push({ node->left, hd - 1 });
		}

		// Add right child to the queue with 
		// horizontal distance + 1
		if (node->right) {
			q.push({ node->right, hd + 1 });
		}
	}

	// Extract the nodes from the map in sorted order 
	  // of their horizontal distances
	for (auto it : bottomNodes) {
		result.push_back(it.second);
	}

	return result;
}

int isBalanced(treeNode* root)
{
	if (root == nullptr)
		return 0;

	int lt = isBalanced(root->left);
	//If left subtree returns -1: it not balanced then return -1 from this call itself
	if (lt == -1)
		return -1;
	int rt = isBalanced(root->right);
	//If right subtree returns -1: it not balanced then return -1 from this call itself
	if (rt == -1)
		return -1;

	//If abs(lt-rt)>1, it's not balanced, return -1.
	if (abs(lt - rt) > 1)
		return -1;

	return 1 + max(lt, rt);
}

bool isBalancedBT(treeNode* root)
{
	return isBalanced(root) != -1;
}

bool isIdenticalTree(treeNode* r1, treeNode* r2)
{
	if (r1 == nullptr || r2 == nullptr)
		return r1 == r2;
	return (r1->data == r2->data) && isIdenticalTree(r1->left, r2->left) && isIdenticalTree(r1->right,  r2->right);
}


bool isSymmetric(treeNode* r1, treeNode* r2)
{
	if (r1 == nullptr || r2 == nullptr)
		return r1 == r2;
	return (r1->data == r2->data) && isSymmetric(r1->left, r2->right) && isSymmetric(r1->right, r2->left);
}

bool isSymmetricalTree(treeNode* r1)
{
	return isSymmetric(r1->left, r1->right);
}

//Binary tree paths:
void checkBinaryTreePath(treeNode* root, string str, vector<string>& path)
{
	if (root == nullptr)
		return;

	//If str is empty, it's first time then append only data
	if (str == " ")
		str = str + to_string(root->data);
	else
		str = str + "->" + to_string(root->data);
	//We need to print root to leaf path: considering Tree-1:
	//10->5->4->2, 10->5->6, 10->20
	if (root->left == nullptr && root->right == nullptr)
		path.push_back(str);

	else
		checkBinaryTreePath(root->left, str, path);
		checkBinaryTreePath(root->right, str, path);
}

vector<string> binaryTreePath(treeNode* root)
{
	vector<string>ans;
	checkBinaryTreePath(root, " ", ans);
	return ans;
}


bool isIdentical(treeNode* root, treeNode* subroot)
{
	if (root == nullptr || subroot == nullptr)
		return root == subroot;
	return (root->data == subroot->data) && isIdentical(root->left, subroot->left) && isIdentical(root->right, subroot->right);
}
bool isSubTree(treeNode* root, treeNode* subroot)
{
	if (subroot == nullptr)
		return true;
	if (root == nullptr)
		return false;
	if (isIdentical(root, subroot))
		return true;
	return isSubTree(root->left, subroot) || isSubTree(root->right, subroot);
}

treeNode* mergeTwoBT(treeNode* r1, treeNode* r2)
{
	if (r1 == nullptr)
		return r2;
	if (r2 == nullptr)
		return r1;
	int merged_data = r1->data + r2->data;
	treeNode* merged = new treeNode(merged_data);
	merged->left = mergeTwoBT(r1->left, r2->left);
	merged->right = mergeTwoBT(r1->right, r2->right);
	
	return merged;
}

bool hasPathSum(treeNode* root, int targetSum)
{
	//Return false if root is null
	if (root == nullptr)
		return false;
	//Return true if we got leaf node and targetSum - root->data = 0
	if (root->left == nullptr && root->right == nullptr && targetSum - root->data == 0)
		return true;

	return hasPathSum(root->left, targetSum - root->data) || hasPathSum(root->right, targetSum - root->data);
}

void calculateSumOfLeftLeaves(treeNode* root, int& ans)
{
	if (root == nullptr)
		return;
	if (root->left)
		if (root->left->left == nullptr && root->left->right == nullptr)
			ans = ans + root->left->data;

	//Traverse left and right subtree
	calculateSumOfLeftLeaves(root->left, ans);
	calculateSumOfLeftLeaves(root->right, ans);

}
int sumOfLeftLeaves(treeNode* root)
{
	int ans = 0;
	calculateSumOfLeftLeaves(root, ans);
	return ans;
}

void flatten(treeNode* root)
{
	treeNode* current = root;
	while (current != NULL)
	{
		if(current->left == NULL)
			current = current->right;
		  else
		  {
			treeNode* prev = current->left;
			  while (prev->right != NULL)
			  {
				  prev = prev->right;
			  }
			  prev->right = current->right;
			  current->right = current->left;
			  current->left = NULL;
		  }
	}
}


//Add node to leaf in binary tree :
void addNodeToLeafNode(treeNode* root)
{
	// if node is null, return
	if (!root)
		return;

	// if node is leaf node, print its data    
	if (!root->left && !root->right)
	{
		//root->left = createNode(root->data);
		//root->right = createNode(root->data);
		return;
	}

	// if left child exists, check for leaf 
	// recursively
	if (root->left)
		addNodeToLeafNode(root->left);

	// if right child exists, check for leaf 
	// recursively
	if (root->right)
		addNodeToLeafNode(root->right);
}

void traversePreOrder(treeNode* temp)
{
	if (temp != NULL)
	{
		cout << " " << temp->data;
		traversePreOrder(temp->left);
		traversePreOrder(temp->right);
	}
}


/*   Tree-1
		10
	   /  \
      5   20
     / \
    4  6
   /
  2
*/

int main(){
	treeNode* root = nullptr;
	root = addNode(root, 10);
	root->left = addNode(root, 5);
	root->right = addNode(root, 20);
	root->left->left = addNode(root, 4);
	root->left->right = addNode(root, 6);
	root->left->left->left = addNode(root, 2);
	cout << "------preOrderTraversalRecursive-----" << endl;
	preOrderTraversalRecursive(root);
	cout << "------inOrderTraversalRecursive-----" << endl;
	inOrderTraversalRecursive(root);
	cout << "------postOrderTraversalRecursive-----" << endl;
	postOrderTraversalRecursive(root);
	cout << "------preOrdertraversalIterative-----" << endl;
	preOrdertraversalIterative(root);
	cout << "------inOrdertraversalIterative-----" << endl;
	inOrdertraversalIterative(root);
	cout << "------search in Binary tree-----" << endl;
	cout<<searchInBinaryTree(root, 14);
	cout << "------max depth/max height in BT-----" << endl;
	cout << "Max depth:" << maxDepthBT(root) << endl;
	cout << "------Diameter BT-----" << endl;
	cout << "Diameter" << diameterOfBT(root) << endl;
	cout << "-----leftView-----" << endl;
	leftView(root);
	cout << "-----rightView-----" << endl;
	rightView(root);
	cout << "-----levelOrderTraversal----" << endl;
	vector<vector<int>>levelOrderTraverse = levelOrderTraversal(root);
	for (const auto& nodes : levelOrderTraverse)
	{
		for (const auto& node : nodes)
		std::cout << node << ' ';
		std::cout << std::endl;
	}
	cout << "-----zigzagTraversal----" << endl;
	vector<vector<int>>zigzagTraverse = zigzagTraversal(root);
	for (const auto& nodes : zigzagTraverse)
	{
		for (const auto& node : nodes) 
		std::cout << node << ' ';
		std::cout << std::endl;
	}
	cout << "----topView----" << endl;
	vector<int> result = topView(root);
	for (int i : result) {
		cout << i <<endl;
	}
	cout << "----bottomView----" << endl;
	vector<int> res = bottomView(root);
	for (int i : res) {
		cout << i << endl;
	}
	cout << "isBalancedBT=" << isBalancedBT(root) << endl;

	/*
	      1           1
        /  \         / \  
       2    2       2   2  
	
	*/
	treeNode* root1 = nullptr;
	root1 = addNode(root1, 1);
	root1->left = addNode(root1, 2);
	root1->right = addNode(root1, 2);
	treeNode* root2 = nullptr;
	root2 = addNode(root2, 1);
	root2->left = addNode(root2, 2);
	root2->right = addNode(root2, 2);

	cout << "isIdenticalTree=" << isIdenticalTree(root1, root2) << endl;

	cout << "isSymmetricalTree=" << isSymmetricalTree(root) << endl;

	cout <<"Binary tree path="  << endl;
	vector<string> ans = binaryTreePath(root);
	for (auto it : ans)
		cout << it << endl;

	cout << "Subtree of another tree" << endl;
	treeNode * root3 = nullptr;
	root3 = addNode(root3, 3);
	root3->left = addNode(root3, 4);
	root3->right = addNode(root3, 5);
	root3->left->left = addNode(root3, 1);
	root3->left->right = addNode(root3, 2);

	treeNode* root4 = nullptr;
	root4 = addNode(root4, 4);
	root4->left = addNode(root4, 1);
	root4->right = addNode(root4, 2);
	cout << "isSubTree=" << isSubTree(root3, root4) << endl;

	cout << "Merge Binary tree" << endl;
	treeNode* root5 = mergeTwoBT(root3, root4);

	cout << "hasPathSum=" << hasPathSum(root, 21) << endl;

	cout << "Sum of left leaves:" << sumOfLeftLeaves(root) << endl;
	return 0;
}
