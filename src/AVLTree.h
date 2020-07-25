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
    /* data */
public:
    AVLTree(/* args */);
    ~AVLTree();
};

AVLTree::AVLTree(/* args */)
{
}

AVLTree::~AVLTree()
{
}
