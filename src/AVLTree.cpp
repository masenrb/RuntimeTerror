#include "AVLTree.h"
#include <iostream>
#include <algorithm>
//Class definitions for AVL Tree
//DEBUGGING
#include <queue>
#include <vector>

//AVLNode constructor
AVLNode::AVLNode(DrugData input)
{
    drug = input;
    left = nullptr;
    right = nullptr;
}

int AVLTree::height(AVLNode *node)
{
    if (node == nullptr)
        return 0;
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return 1 + std::max(leftHeight, rightHeight);
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

//Insert Helper Functions
AVLNode *AVLTree::insertHelper(AVLNode *node, DrugData input)
{
    //If the node is null add the new node
    if (node == nullptr)
    {
        return (new AVLNode(input));
    }

    //if node isn't null then compare with children to determine placement
    int alphaCompare = node->drug.pName.compare(input.pName);

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

    //Check for balance
    int balanceFactor = height(node->left) - height(node->right);

    //R R nodes
    if (balanceFactor < -1 && (node->right->drug.pName.compare(input.pName) < 0))
    {
        cout << "Left Rotation on " << node->drug.pName << endl;
        return leftRotation(node);
    }
    
    //L L nodes
    if (balanceFactor > 1 && (node->left->drug.pName.compare(input.pName) > 0))
    {
        cout << "Right Rotation on " << node->drug.pName << endl;
        return rightRotation(node);
    }

    //R L nodes
    if (balanceFactor < -1 && (node->right->drug.pName.compare(input.pName) > 0))
    {
        cout << "Right Left Rotation on " << node->drug.pName << endl;
        return rightLeftRotation(node);
    }

    //L R nodes
    if (balanceFactor > 1 && (node->left->drug.pName.compare(input.pName) < 0))
    {
        cout << "Left Right Rotation on " << node->drug.pName << endl;
        return leftRightRotation(node);
    }

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
void AVLTree::levelOrder(AVLNode *root)
{
    if (root != nullptr)
    {
        queue<AVLNode *> queue;
        int levelnum = 1;
        queue.push(root);

        while (!queue.empty())
        {
            int qSize = queue.size(); //Keeping a consitant size
            vector<std::string> level;
            for (int i = 0; i < qSize; i++)
            {
                AVLNode *temp = queue.front();     //Looking at the first node in the queue
                level.push_back(temp->drug.pName); //Adding it's value to the level list
                queue.pop();                       //Removing first in queue node

                if (temp->left != nullptr)
                    queue.push(temp->left);
                if (temp->right != nullptr)
                    queue.push(temp->right);
            }

            cout << "Level: " << levelnum << endl;
            for (int i = 0; i < level.size(); i++)
            {
                cout << level[i] << " ";
            }
            cout << endl;
            levelnum++;
        }
    }
}

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

    DrugData a, b, c, d, e, f;
    a.pName = "a";
    b.pName = "b";
    c.pName = "c";
    d.pName = "d";
    e.pName = "e";
    f.pName = "f";

    tree.insert(a); //1
    tree.insert(b); //2
    tree.insert(d); //4
    tree.insert(e); //5
    tree.insert(f); //6
    tree.insert(c); //3

    cout << "Level Order:" << endl;
    tree.levelOrder(tree.root);
    cout << endl;

    cout << "Inorder Traversal:" << endl;
    tree.inorderTraversal(tree.root);

    cout << "Root: " << tree.root->drug.pName << endl;
    return 0;
}
