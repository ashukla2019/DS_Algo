//Recursive approach
vector<int> inOrderVector; 
vector<int> inorderTraversal(TreeNode* root) 
    {
        if (root != 0) {
            inorderTraversal(root->left);
            inOrderVector.push_back(root->val);
            inorderTraversal(root->right);
        }
        return inOrderVector;
    }
