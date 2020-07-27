#include "AVLTree.h"
#include <iostream>
#include <algorithm>
//Class definitions for AVL Tree

//AVLNode constructor
AVLNode::AVLNode(DrugData input)
{
    drug = input;
    left = nullptr;
    right = nullptr;
    height = 0;
}

//Rotations
AVLNode *AVLTree::leftRotation(AVLNode *node)
{
    //Rotate node left
    AVLNode *newParent = node->right;
    AVLNode *grandChild = node->right->left;
    newParent->left = node;
    node->right = grandChild;

    //Update Node Heights
    newParent->height = std::max(newParent->left->height, newParent->right->height);
    grandChild->height = std::max(grandChild->left->height, grandChild->right->height);
    newParent->height++;
    grandChild->height++;

    return newParent;
}

AVLNode *AVLTree::rightRotation(AVLNode *node)
{
    //Rotate node right
    AVLNode *newParent = node->left;
    AVLNode *grandChild = node->left->right;
    newParent->right = node;
    node->left = grandChild;

    //Update Node Heights
    newParent->height = std::max(newParent->left->height, newParent->right->height);
    grandChild->height = std::max(grandChild->left->height, grandChild->right->height);
    newParent->height++;
    grandChild->height++;

    return newParent;
}

AVLNode *AVLTree::leftRightRotation(AVLNode *node)
{
    //Don't preform operations if empty tree
    if (node != nullptr)
        return;

    //Right rotate right node
    node->right = leftRotation(node->right);

    //Left rotate
    return rightRotation(node);
}

//Insert Helper Functions
AVLNode *AVLTree::insertHelper(AVLNode *node, DrugData input)
{
    //If the node is null add the new node
    if (node == nullptr)
    {
        return (new AVLNode(input));
    }

    //if node isn't null then compare with children to determine placement
    if (input.pName.compare(node->drug.pName) < 0) //If new drug is alpha before node
    {
        node->left = insertHelper(node->left, input);
    }
    else if (input.pName.compare(node->drug.pName) > 0) //If new drug is alpha after node
    {
        node->right = insertHelper(node->right, input);
    }
    else //If the new drug duplicate then ignore it
    {
        return node;
    }


    //Update the hight of node as new node was added
    node->height = std::max(node->left->height,node->right->height);
    node->height++;

    //Check for balance
    int balanceFactor = node->left->height - node->right->height;

    //R R nodes
    if(balanceFactor < -1 && input.pName.compare(node->right->drug.pName) > 0)
    {
        return leftRotation(node);
    }

    //L L nodes
    if(balanceFactor > 1 && input.pName.compare(node->left->drug.pName) < 0)
    {
        return rightRotation(node);
    }

    return node;

}

//Insert
void AVLTree::insert(DrugData drug)
{
    //Call recursive insertHelper with node starting at the top
    root = insertHelper(root, drug);
}

//Debugging
void AVLTree::inorderTraversal(AVLNode *node)
{
    if (node != nullptr)
    {
        inorderTraversal(node->left);
        std::cout << node->drug.pName << " ";
        inorderTraversal(node->right);
    }
}

int main()
{
    AVLTree tree;

    DrugData a, b, c;
    a.pName = "a";
    b.pName = "b";
    c.pName = "c";

    tree.insert(a);
    tree.insert(b);
    tree.insert(c);

    tree.inorderTraversal(tree.root);

    return 0;
}