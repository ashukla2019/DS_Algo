Recursive Approach:
Time complexity: O(n)
Space complexity: O(n)

void inOrderTrav(node * curr, vector < int > & inOrder) {
  if (curr == NULL)
    return;

  inOrderTrav(curr -> left, inOrder);
  inOrder.push_back(curr -> data);
  inOrderTrav(curr -> right, inOrder);
}

  -------------------------------------------------------------------------
//Recursive Approach:
Time complexity: O(n)
Space complexity: O(n)
vector < int > inorderTraversal(TreeNode * curr) 
  {
    vector<int>ans; 
    //Base case: 
    if(curr==NULL)
        return ans;
    stack<TreeNode*>s;
    //This is required to make recursive environemnt
    while(true)
    {
        //We iterate through leftsubtree and push node to stack      until we get null
        //If curr is null, then print/push val to vector and pop it
        //Now iterate through right sub tree until we get null
        if(curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        else
        {
            if(s.empty())
                break;
            curr = s.top();
            ans.push_back(curr->val);
            s.pop();
            curr = curr->right;    
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
 
