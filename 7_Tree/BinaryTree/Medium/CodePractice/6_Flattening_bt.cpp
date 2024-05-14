/*
Morris traversal approach:
1) set current to root
2) Traverse until current is not null
3) check if current->left is not null then set prev to current->left
4) Check right of prev until it is not null, when it's null set prev->right = current->right
5) set current->right = current->left and remove current->left
6) Now set current=current->right(else part of if(current->left == NULL)

Time complecity:O(n)
Space complexity: O(1)
*/  

void flatten(TreeNode* root) 
    {
      TreeNode* current = root;
      while(current != NULL)
      {
          if(current->left != NULL)
          {
              TreeNode* prev= current->left;
              while(prev->right != NULL)
              {
                  prev = prev->right;
              }
              prev->right = current->right;
              current->right= current->left;
              current->left = NULL;
          }
          current = current->right;
      }
    }
