#include "AVLTree.h"
#include "CSV_Import.h"
#include <iostream>
#include <algorithm>
//Class definitions for AVL Tree
//DEBUGGING
#include <queue>

//AVLNode constructor
AVLNode::AVLNode(DrugData input)
{
    drug = input;
    left = nullptr;
    right = nullptr;
}

//AVLTree Constructor and Destructor
AVLTree::AVLTree() //Mostly empty constructor
{
    root = nullptr;
}

AVLTree::~AVLTree()
{
    deleteTree(root); //Delete the tree starting at the root

    //Delete all returned pointers
    for (int i = 0; i < dataPointers.size(); i++)
    {
        delete dataPointers[i];
    }
}

int AVLTree::alphaCompare(AVLNode *node, DrugData input)
{
    return node->drug.pName.compare(input.pName);
}

//Rotations
AVLNode *AVLTree::leftRotation(AVLNode *node)
{
    //Rotate node left
    AVLNode *newParent = node->right;
    AVLNode *grandChild = node->right->left;
    newParent->left = node;
    node->right = grandChild;

    return newParent;
}

AVLNode *AVLTree::rightRotation(AVLNode *node)
{
    //Rotate node right
    AVLNode *newParent = node->left;
    AVLNode *grandChild = node->left->right;
    newParent->right = node;
    node->left = grandChild;

    return newParent;
}

AVLNode *AVLTree::leftRightRotation(AVLNode *node)
{
    //Right rotate right node
    node->left = leftRotation(node->left);

    //Left rotate
    return rightRotation(node);
}

AVLNode *AVLTree::rightLeftRotation(AVLNode *node)
{
    //Right rotate right node
    node->right = rightRotation(node->right);

    //Left rotate
    return leftRotation(node);
}

//Recursive Helpers
void AVLTree::deleteTree(AVLNode *node)
{
    if (node == nullptr)
        return;

    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

int AVLTree::height(AVLNode *node)
{
    if (node == nullptr)
        return 0;
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return 1 + std::max(leftHeight, rightHeight);
}

AVLNode *AVLTree::insertHelper(AVLNode *node, DrugData input)
{
    //If the node is null add the new node
    if (node == nullptr)
    {
        return (new AVLNode(input));
    }

    //if node isn't null then compare with children to determine placement
    if (alphaCompare(node, input) > 0) //If new drug is alpha before node
    {
        node->left = insertHelper(node->left, input);
    }
    else if (alphaCompare(node, input) < 0) //If new drug is alpha after node
    {
        node->right = insertHelper(node->right, input);
    }
    else //If the new drug duplicate then merge it with already existing drug
    {
        node->drug.mergeDrug(input);
        return node;
    }

    //Check for balance
    int balanceFactor = height(node->left) - height(node->right);

    //R R nodes
    if (balanceFactor < -1 && alphaCompare(node->right, input) < 0)
    {
        //cout << "Left Rotation on " << node->drug.pName << endl;
        return leftRotation(node);
    }

    //L L nodes
    if (balanceFactor > 1 && alphaCompare(node->left, input) > 0)
    {
        //cout << "Right Rotation on " << node->drug.pName << endl;
        return rightRotation(node);
    }

    //R L nodes
    if (balanceFactor < -1 && alphaCompare(node->right, input) > 0)
    {
        //cout << "Right Left Rotation on " << node->drug.pName << endl;
        return rightLeftRotation(node);
    }

    //L R nodes
    if (balanceFactor > 1 && alphaCompare(node->left, input) < 0)
    {
        //cout << "Left Right Rotation on " << node->drug.pName << endl;
        return leftRightRotation(node);
    }

    //Return root pointer
    return node;
}

AVLNode *AVLTree::searchHelper(AVLNode *node, string name)
{
    if(node == nullptr || node->drug.pName.compare(name) == 0)
        return node;
    else if(node->drug.pName.compare(name) > 0)
        return searchHelper(node->left, name);
    else
        return searchHelper(node->right, name);
}

//Insert
void AVLTree::insert(DrugData drug)
{
    //Call recursive insertHelper with node starting at the top
    root = insertHelper(root, drug);
}

//Search
DrugData *AVLTree::search(string name)
{
    AVLNode *returnNode = searchHelper(root,name);

    //If node is not found return nullptr
    if(returnNode == nullptr)
        return nullptr;

    //Returning pointer to Drugdata class
    DrugData *returnDrugData = new DrugData(returnNode->drug);

    //Place in vector for later deletion
    dataPointers.push_back(returnDrugData);

    //Return new pointer
    return returnDrugData;
}
