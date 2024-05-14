//Function to return a list containing elements of left view of the binary tree.
Time Complexity: O(N)
Space Complexity: O(H)       (H -> Height of the Tree)

/*
We need to follow approach: Rt L R(preorder-recursive), can not follow level order traversal
as it will increase time complexity
Used vector to store node value
When vector::size() == level means first node of that level: 
*/
void checkLeftView(Node* root, int level, vector<int>&ans)
{
	if(root == NULL)
		return;
	if(ans.size()==level)
		ans.push_back(root->data);

  checkLeftView(root->left, level+1, ans);	
	checkLeftView(root->right, level+1, ans);
		
}

vector<int> leftView(Node *root)
{
   vector<int>ans;
   checkLeftView(root, 0, ans);
   return ans;
}

