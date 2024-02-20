  int maxDepth(TreeNode* root) 
    {
        //Base case:
        if(root==NULL)
            return 0; //return 0 height if root is null
        int ltree = maxDepth(root->left);  
        int rtree = maxDepth(root->right);  
        return 1+ max(ltree, rtree);
    }
