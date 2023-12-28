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
