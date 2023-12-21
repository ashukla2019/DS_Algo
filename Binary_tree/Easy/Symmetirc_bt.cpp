//Symmetric BT: left subtree should be mirror of right subtree
bool isSymmetric(TreeNode* root) 
    {
        if(root==NULL)
            return true;
        return isSymmetricBT(root->left, root->right);    
    }

    bool isSymmetricBT(TreeNode* lt, TreeNode* rt)
    {
        if(lt==NULL || rt==NULL)
            return lt==rt;
        return (lt->val==rt->val) && isSymmetricBT(lt->right, rt->left) && isSymmetricBT(lt->left, rt->right);      
    }      
