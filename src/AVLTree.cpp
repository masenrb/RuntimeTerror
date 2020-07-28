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
    height = 1;
}

int AVLTree::getHeight(AVLNode *node)
{
    if(node == nullptr)
        return 0;
    return node->height;
}

int AVLTree::getMaxHeight(AVLNode *node1,AVLNode *node2)
{
    int height = std::max(getHeight(node1),getHeight(node2));
    return height;
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
    newParent->height = getMaxHeight(newParent->left,newParent->right);
    node->height = getMaxHeight(node->left,node->right);
    newParent->height++;
    node->height++;

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
    newParent->height = getMaxHeight(newParent->left,newParent->right);
    node->height = getMaxHeight(node->left,node->right);
    newParent->height++;
    node->height++;

    return newParent;
}

AVLNode *AVLTree::leftRightRotation(AVLNode *node)
{
    //Don't preform operations if empty tree
    if (node != nullptr)
        return nullptr;

    //Right rotate right node
    node->left = leftRotation(node->left);

    //Left rotate
    return rightRotation(node);
}

AVLNode *AVLTree::rightLeftRotation(AVLNode *node)
{
    //Don't preform operations if empty tree
    if (node != nullptr)
        return nullptr;

    //Right rotate right node
    node->right = rightRotation(node->right);

    //Left rotate
    return leftRotation(node);
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
    int alphaCompare = input.pName.compare(node->drug.pName);
 
    if (alphaCompare > 0) //If new drug is alpha before node
    {
        node->left = insertHelper(node->left, input);
    }
    else if (alphaCompare < 0) //If new drug is alpha after node
    {
        node->right = insertHelper(node->right, input);
    }
    else //If the new drug duplicate then ignore it
    {
        return node;
    }

    //Update the hight of node as new node was added
    node->height = getMaxHeight(node->right,node->left);
    node->height++;

    //Check for balance
    int balanceFactor = getHeight(node->left) - getHeight(node->right);
    
    //R R nodes
    if(balanceFactor < -1 && alphaCompare < 0)
    {
        return leftRotation(node);
    }

    //L L nodes
    if(balanceFactor > 1 && alphaCompare > 0)
    {
        return rightRotation(node);
    }

    // //R L nodes
    // if(balanceFactor < -1 && input.pName.compare(node->right->drug.pName) < 0)
    // {
    //     return rightLeftRotation(node);
    // }

    // //L R nodes
    // if(balanceFactor > 1 && input.pName.compare(node->left->drug.pName) > 0)
    // {
    //     return leftRightRotation(node);
    // }

    //Return root pointer
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

    tree.insert(c);
    tree.insert(b);
    tree.insert(a);


    tree.inorderTraversal(tree.root);

    return 0;
}
