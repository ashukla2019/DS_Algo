Problem Statement: Print Root to Node Path In A Binary Tree. Write a program to print path from root to 
a given node in a binary tree.
Problem Description: 
We are given a binary tree T and a node V. We need to print a path from the root of the tree to the node.

Note:
No two nodes in the tree have the same data value.
It is assured that the node V is present and a path always exists.

---------------------------------------------------------------------------  
bool getPath(node * root, vector < int > & vec, int x) {
  // if root is NULL
  // there is no path
  if (!root)
    return false;

  // push the node's value in 'arr'
  vec.push_back(root -> data);

  // if it is the required node
  // return true
  if (root -> data == x)
    return true;

  // else check whether the required node lies
  // in the left subtree or right subtree of
  // the current node
  if (getPath(root -> left, vec, x) ||
    getPath(root -> right, vec, x))
    return true;

  // required node does not lie either in the
  // left or right subtree of the current node
  // Thus, remove current node's value from
  // 'arr'and then return false   
  vec.pop_back();
  return false;
}
