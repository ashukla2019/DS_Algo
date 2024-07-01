/*Diameter: The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
The length of a path between two nodes is represented by the number of edges between them.
Approach:
1) Since Daimeter is max path between two nodes => (ltree + rtree) at any node => ltree/rthree of nth node would be height of n-1th node
   we should calculate and return height of every node, that would become ltree or rtee
2) Diameter = max(diameter, ltree + rtree)
*/  

int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }

    int height(TreeNode* root, int& diameter) {

        if (root==NULL) 
        {
            return 0;
        }

        int lh = height(root->left, diameter);
        int rh = height(root->right, diameter);

        diameter = max(diameter, lh + rh);

        return 1 + max(lh, rh);
    }
