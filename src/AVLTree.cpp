#include "AVLTree.h"
//Class definitions for AVL Tree

//AVLNode constructor
AVLNode::AVLNode(DrugData input)
{
    drug = input;
    left = nullptr;
    right = nullptr;
    height = 1; 
}

//Rotations
AVLNode* AVLTree::leftRotation(AVLNode *node)
{
    //Rotate node left
    AVLNode* newParent = node->right;
    AVLNode* grandChild = node->right->left;
    newParent->left = node;
    node->right = grandChild;
    return newParent;
}

AVLNode* AVLTree::rightRotation(AVLNode *node)
{
    //Rotate node right
    AVLNode* newParent = node->left;
    AVLNode* grandChild = node->left->right;
    newParent->right = node;
    node->left = grandChild;
    return newParent;
}

AVLNode* AVLTree::leftRightRotation(AVLNode *node)
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

//Insert Helper Functions
AVLNode* AVLTree::insertHelper(AVLNode *node, DrugData input)
{
    //If the node is null add the new node
    if(node == nullptr)
    {
        return(new AVLNode(input));
    }

    //if node isn't null then compare with children to determine placement
    if(input.pName.compare(node->drug.pName) < 0) //If new drug is alpha lower then node
    {
        node->left = insertHelper(node->left, input);
    }
    else if(input.pName.compare(node->drug.pName) > 0) //If new drug is alpha higher then node
    {
        node->right = insertHelper(node->right, input);
    }
    else //If the new drug duplicate then ignore it
    {
        return node;
    }
    
}

//Insert
void AVLTree::insert(DrugData drug)
{
    //Call recursive insertHelper with node starting at the top
    root = insertHelper(root,drug);
}