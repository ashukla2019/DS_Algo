/*
Approach:
1) We will call method isSymmetricBT with two args root->left and root->right
2) Check if left or right null, if anyone is null then return lt==rt
3) Check lt->val==rt->val && recursively check below condition:
   (lt->left, rt->right) &&(lt->right, rt->left)

*/  
bool isSymmetric(TreeNode* root) 
    {
        if(root==NULL)
            return true;
        return isSymmetricBT(root->left, root->right);    
    }
private:
    bool isSymmetricBT(TreeNode* lt, TreeNode* rt)
    {
        if(lt==NULL || rt==NULL)
            return lt==rt;
        return (lt->val==rt->val) && isSymmetricBT(lt->right, rt->left) && isSymmetricBT(lt->left, rt->right);      
    }        
