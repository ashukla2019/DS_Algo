//Check value at left tree and right tree
//Check left tree
//Check right tree
bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        if(p==NULL || q==NULL )
        {
            return p==q;
        }
       
        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        
    }
