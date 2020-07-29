#pragma once
#include "DrugData.h"

class MapNode{
private:
    string key;
    DrugData value;
    MapNode *next;

public:
    MapNode(string key, DrugData value);
    string getKey();
    DrugData getValue();
    MapNode *getNextNode();
    void setNextNode(MapNode *next);
    void setValue(DrugData value);
};

class HashMap{
private:
    vector<MapNode*> map;
public:
    HashMap(int numDataRows, float loadCapacity);
    ~HashMap();

    int hashFunction(string key);
    void addNode(string key, DrugData value);

};