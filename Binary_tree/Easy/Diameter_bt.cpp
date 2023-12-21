//Diameter: 
//1) Longest path b/w 2 nodes
//2) It is not mandatory to pass through root.  
//Diameter would be maximum height of ltree+ height of rtree of any node in Binary tree. We need to traverse 
//all nodes to check height of left subtree and right subtree and also we need to pass diameter to height function
//and update diameter.

int diameterOfBinaryTree(TreeNode* root) 
    {
        int diameter=0;
        height(root, diameter); //passing diameter
        return diameter;
    }
 int height(TreeNode* root, int& diameter)
 {
        if(root==NULL)
            return 0;
        int ltree=height(root->left, diameter);  
        int rtree=height(root->right, diameter); 
        diameter=max(diameter, ltree+rtree); //every step, we are checking if diamter is max or ltree+rtee is max
        return 1+max(ltree,rtree); 
  }    
