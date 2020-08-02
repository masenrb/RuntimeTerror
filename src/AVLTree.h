#pragma once
#include "DrugData.h"
#include <vector>

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
    AVLNode *root = nullptr;

    //Rotations
    AVLNode* leftRotation(AVLNode *node);
    AVLNode* rightRotation(AVLNode *node);
    AVLNode* leftRightRotation(AVLNode *node);
    AVLNode *rightLeftRotation(AVLNode *node);

    //Helper Functions
    int alphaCompare(AVLNode *node, DrugData input);

    //Recursive Helper Functions
    AVLNode* insertHelper(AVLNode *node, DrugData input);
    AVLNode* searchHelper(AVLNode *node, string name);
    int height(AVLNode* node);
    void deleteTree(AVLNode *node);

    //Vector to keep track of data pointers
    vector<DrugData *> dataPointers;

public:
    void insert(DrugData input);
    DrugData* search(string name);

    //Constructor and Destructor
    AVLTree();
    AVLTree(vector<DrugData> drugVector);
    ~AVLTree();
};
