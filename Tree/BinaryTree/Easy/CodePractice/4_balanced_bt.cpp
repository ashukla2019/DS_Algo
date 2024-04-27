/*
Binary tree would be balanced, when abs(ltree-rtree))<=1
Approach: 
1) Call different function to calculate height of binary tree 
2) Check abs(ltree - rtree) > 1 then return -1 => not balanced
3) Check ltree and rtee value as well for -1, if it's -1 then return -1 for both cases and height will not be calculated further.

Time Complexity: O(N) 
Space Complexity: O(1) Extra Space + O(H) Recursion Stack space (Where “H”  is the height of binary tree)

*/
bool isBalanced(TreeNode* root) 
    {
        return dfsHeight (root) != -1;
    }

    int dfsHeight (TreeNode *root) 
    {

        if (root == NULL) 
            return 0;
        
        int leftHeight = dfsHeight (root -> left);

        if (leftHeight == -1) 
            return -1;
        
        int rightHeight = dfsHeight (root -> right);

        if (rightHeight == -1) 
            return -1;
        
        if (abs(leftHeight - rightHeight) > 1)  
            return -1;

        return max (leftHeight, rightHeight) + 1;
    }
