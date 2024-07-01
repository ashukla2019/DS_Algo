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

//Iterative function for inorder tree traversal
void inOrder(struct Node* root)
{
    stack<Node*> s;
    Node* curr = root;
 
    while (curr != NULL || s.empty() == false) {
         
        // Reach the left most Node of the
        // curr Node
        while (curr != NULL) {
             
            // Place pointer to a tree node on
            // the stack before traversing
            // the node's left subtree
            s.push(curr);
            curr = curr->left;
        }
 
        // Current must be NULL at this point
        curr = s.top();
        s.pop();
 
        cout << curr->data << " ";
 
        // we have visited the node and its
        // left subtree.  Now, it's right
        // subtree's turn
        curr = curr->right;
 
    }
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
 
