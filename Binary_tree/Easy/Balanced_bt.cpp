//Binary tree will be balanced only if abs(ltree-rtree)<=1, else unbalanced binary tree.
//We need to calculate height of left and right subtree and if it gets -1.
 bool isBalanced(TreeNode* root)
    {
        return dfsHeight(root) !=-1;
    }
    int dfsHeight(TreeNode* root) 
    {
        if(root==NULL)
            return 0;
        int ltree=dfsHeight(root->left);
        if(ltree ==-1)
            return -1;
        int rtree=dfsHeight(root->right);
        if(rtree ==-1)
            return -1;  
        if(abs(ltree-rtree)>1)
            return -1;
        return 1+ max(ltree,rtree);              
    }
