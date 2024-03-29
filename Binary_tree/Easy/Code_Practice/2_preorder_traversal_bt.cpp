Recursive traversal:
vector<int> Preorder(TreeNode* root)
{
    vector<int>ans;
    if (root == NULL)
        return ans;

    // Deal with the node
    ans.push_back(root->val);

    // Recur on left subtree
    Preorder(root->left);

    // Recur on right subtree
    Preorder(root->right);
}
-----------------------------------------------------------------------------------
//Iterative way of traversal
//Time complexity:O(n)
//Space complexity:O(n)
vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int>ans;
        // Base Case
    if (root == NULL)
        return ans;
 
    // Create an empty stack and push root to it
    stack<TreeNode*> nodeStack;
    nodeStack.push(root);
 
    /* Pop all items one by one. Do following for every popped item
       a) print it
       b) push its right child
       c) push its left child
    Note that right child is pushed first so that left is processed first */
    while (!nodeStack.empty()) 
    {
        // Pop the top item from stack and print it
        root = nodeStack.top();
        ans.push_back(root->val);
        nodeStack.pop();
 
        // Push right and left children of the popped node to stack
        if (root->right)
            nodeStack.push(root->right);
        if (root->left)
            nodeStack.push(root->left);
    }
    return ans;
  }
