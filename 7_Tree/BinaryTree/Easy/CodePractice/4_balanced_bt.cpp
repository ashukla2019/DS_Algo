/*
             4
            / \
           7   8
              /  
             1 
            / \
           3   5
Binary tree would be balanced, when abs(ltree-rtree))<=1
Approach: 
1) Call different function to calculate height of binary tree 
2) Check abs(ltree - rtree) > 1 then return -1 => not balanced
3) Check ltree and rtee value as well for -1, if it's -1 then return -1 for both cases and height will not be calculated further.

Time Complexity: O(N) 
Space Complexity: O(1) Extra Space + O(H) Recursion Stack space (Where “H”  is the height of binary tree)

*/
  bool isBalanced(Node* root) {
        // Check if the tree's height difference
        // between subtrees is less than 2
        // If not, return false; otherwise, return true
        return dfsHeight(root) != -1;
    }

    // Recursive function to calculate
    // the height of the tree
    int dfsHeight(Node* root) {
        // Base case: if the current node is NULL,
        // return 0 (height of an empty tree)
        if (root == NULL) return 0;

        // Recursively calculate the
        // height of the left subtree
        int leftHeight = dfsHeight(root->left);

        // If the left subtree is unbalanced,
        // propagate the unbalance status
        if (leftHeight == -1) 
            return -1;

        // Recursively calculate the
        // height of the right subtree
        int rightHeight = dfsHeight(root->right);

        // If the right subtree is unbalanced,
        // propagate the unbalance status
        if (rightHeight == -1) 
            return -1;

        // Check if the difference in height between
        // left and right subtrees is greater than 1
        // If it's greater, the tree is unbalanced,
        // return -1 to propagate the unbalance status
        if (abs(leftHeight - rightHeight) > 1)  
            return -1;

        // Return the maximum height of left and
        // right subtrees, adding 1 for the current node
        return max(leftHeight, rightHeight) + 1;
    }
