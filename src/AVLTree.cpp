#include "AVLTree.h"
//Class definitions for AVL Tree

//Rotations
Node* AVLTree::leftRotation(Node *node)
{
    //Rotate node left
    Node* newParent = node->right;
    Node* grandChild = node->right->left;
    newParent->left = node;
    node->right = grandChild;
    return newParent;
}

Node* AVLTree::rightRotation(Node *node)
{
    //Rotate node right
    Node* newParent = node->left;
    Node* grandChild = node->left->right;
    newParent->right = node;
    node->left = grandChild;
    return newParent;
}

Node* AVLTree::leftRightRotation(Node *node)
{
    //Don't preform operations if empty tree
    if(node != nullptr)
    {
        //Right rotate right node
        node->right = leftRotation(node->right);
        
        //Left rotate
        return rightRotation(node);
    }
}