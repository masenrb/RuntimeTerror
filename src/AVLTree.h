#pragma once
#include "DrugData.h"

struct AVLNode
{
    DrugData drug;
    AVLNode *left = nullptr;
    AVLNode *right = nullptr;

    AVLNode(DrugData input);
};

class AVLTree
{
private:
    //Rotations
    AVLNode* leftRotation(AVLNode *node);
    AVLNode* rightRotation(AVLNode *node);
    AVLNode* leftRightRotation(AVLNode *node);
    AVLNode *rightLeftRotation(AVLNode *node);

    //Helper Functions
    int alphaCompare(AVLNode *node, DrugData input);

    //Recursive Helper Functions
    AVLNode* insertHelper(AVLNode *node, DrugData input);
    int height(AVLNode* node);
    void deleteTree(AVLNode *node);

public:
    void insert(DrugData input);
    AVLTree();
    ~AVLTree();

    //Debugging
    void levelOrder(AVLNode* root);
    void inorderTraversal(AVLNode *node);

    //Move to private after debugging
    AVLNode *root = nullptr;
};
