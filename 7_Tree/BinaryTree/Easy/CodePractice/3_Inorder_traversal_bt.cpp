Recursive Approach:
Time complexity: O(n)
Space complexity: O(n)

vector<int> inOrder(TreeNode* root)
{
    vector<int>ans;
    if (root == NULL)
        return ans;

  inOrderTrav(curr -> left);
  inOrder.push_back(curr -> data);
  inOrderTrav(curr -> right);
}


  -------------------------------------------------------------------------
//Recursive Approach:
Time complexity: O(n)
Space complexity: O(n)
vector < int > inorderTraversal(TreeNode * root) 
  {
    
    vector<int>ans;
	
    //Base case:
	if(root==NULL)
		return ans;
	stack<TreeNode*> s;
    TreeNode* current=root;
	while(!s.empty() || current !=nullptr)
	{
		if(current !=nullptr)
		{
			s.push(current);
			current=current->left;
		}
		else
		{
			current=s.top();
			s.pop();
			ans.push_back(current->val);
			current=current->right;
		}
		
    }
	return ans;
  }
 
--------------------------------------------------------------------------------------------
Time complexity: O(n)
Space complexity: O(1)
  Morris inorder traversal:
  vector<int> MorrisTraversal(TreeNode* root)
{
	vector<int>ans;
    if (root == NULL)
        return;
 
    TreeNode* current = root;
    while (current != NULL) 
	{
 
        if (current->left == NULL) 
		{
            ans.push_back(root->val);
            current = current->right;
        }
        else 
		{
 
            /* Find the inorder predecessor of current */
            pre = current->left;
            while (pre->right != NULL && pre->right != current)
                pre = pre->right;
 
            /* Make current as the right child of its
               inorder predecessor */
            if (pre->right == NULL) {
                pre->right = current;
                current = current->left;
            }
 
            /* Revert the changes made in the 'if' part to
               restore the original tree i.e., fix the right
               child of predecessor */
            else {
                pre->right = NULL;
                ans.push_back(root->val);
                current = current->right;
            } /* End of if condition pre->right == NULL */
        } /* End of if condition current->left == NULL*/
    } /* End of while */
	return ans;
}
 
