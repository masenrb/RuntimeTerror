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
    //Helper functions
    AVLNode* leftRotation(AVLNode *node);
    AVLNode* rightRotation(AVLNode *node);
    AVLNode* leftRightRotation(AVLNode *node);
    AVLNode *rightLeftRotation(AVLNode *node);

    AVLNode* insertHelper(AVLNode *node, DrugData input);

public:
    void insert(DrugData input);
    // AVLTree();
    // AVLTree(DrugData input);
    // ~AVLTree();

    //Debugging
    void levelOrder(AVLNode* root);
    void inorderTraversal(AVLNode *node);

    int height(AVLNode* node);
    //Move to private after debugging
    AVLNode *root = nullptr;
};
