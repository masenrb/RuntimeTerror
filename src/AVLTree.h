#pragma once
#include "DrugData.h"

struct Node
{
    DrugData drug;
    Node *left = nullptr;
    Node *right = nullptr;
};

class AVLTree
{
private:
    Node *root = nullptr;
    
    //Helper functions
    Node* leftRotation(Node *node);
    Node* rightRotation(Node *node);
    Node* leftRightRotation(Node *node);
public:
    void insert(DrugData input);
    AVLTree();
    AVLTree(DrugData input);
    ~AVLTree();
};
