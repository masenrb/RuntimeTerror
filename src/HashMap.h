#pragma once
#include "DrugData.h"

class MapNode{
private:
    string key;
    DrugData *value;
    MapNode *next;

public:
    MapNode(string key, DrugData *value);
    string getKey();
    DrugData *getValue();
    MapNode *getNextNode();
    void setNextNode(MapNode *next);
};

class HashMap{
private:
    int numRows;
    vector<MapNode*> map;
public:
    HashMap();
    HashMap(int dataSize);
    ~HashMap();

    int hashFunction(string key);
    void addNode(DrugData value);
    void deleteNode(string key);
    DrugData *getData(string key);

};
