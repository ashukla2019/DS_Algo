#include <stdlib.h>
#include <iostream>

using namespace std;

class treeNode 
{
public:
    int data;
    treeNode* left;
    treeNode* right;
};

// New node creation
treeNode* createNode(int data) 
{
    treeNode* node = new treeNode();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

void addNodeToLeafNode(treeNode* root)
{
    // if node is null, return
    if (!root)
        return;

    // if node is leaf node, print its data    
    if (!root->left && !root->right)
    {
        root->left = createNode(root->data);
        root->right = createNode(root->data);
        return;
    }

    // if left child exists, check for leaf 
    // recursively
    if (root->left)
        addNodeToLeafNode(root->left);

    // if right child exists, check for leaf 
    // recursively
    if (root->right)
        addNodeToLeafNode(root->right);
}

void traversePreOrder(treeNode* temp)
{
    if (temp != NULL) 
    {
        cout << " " << temp->data;
        traversePreOrder(temp->left);
        traversePreOrder(temp->right);
    }
}

int main() {
    treeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->right->left = createNode(5);

    //addNodeToLeafNode(root);
    traversePreOrder(root);

}
