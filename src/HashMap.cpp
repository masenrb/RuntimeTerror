#include "HashMap.h"
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

const float LOAD_CAPACITY = .67;
const int NUM_DATA_ROWS = 100;

MapNode::MapNode(string key, DrugData *value)
{
    this->key = key;
    this->value = value;
    this->next = nullptr;
}

string MapNode::getKey()
{
    return key;
}

DrugData *MapNode::getValue()
{
    return value;
}

MapNode *MapNode::getNextNode()
{
    return next;
}

void MapNode::setNextNode(MapNode *next)
{
    this->next = next;
}

HashMap::HashMap()
{
    map = vector<MapNode *>((int)(NUM_DATA_ROWS / LOAD_CAPACITY), nullptr);
}

HashMap::HashMap(vector<DrugData> importDrugs)
{
    map = vector<MapNode *>((int)(importDrugs.size() / LOAD_CAPACITY), nullptr);
    for (int i = 0; i < importDrugs.size(); i++)
    {
        addNode(importDrugs[i].pName, importDrugs[i]);
    }
}

HashMap::~HashMap()
{
    for (int i = 0; i < map.size(); i++)
    {
        if (map[i] != nullptr)
        {
            MapNode *nextNode = map[i];
            while (nextNode != nullptr)
            {
                MapNode *prevNode = nextNode;
                nextNode = (*nextNode).getNextNode();
                delete (*prevNode).getValue();
                delete prevNode;
            }
        }
    }
}

int HashMap::hashFunction(string key)
{
    const int power = 31;
    int counter = 0;
    long long hashValue = 0;
    for (char c : key)
    {
        hashValue = hashValue + c * pow(power, counter);
        counter++;
    }
    int final = abs(hashValue % ((int)(NUM_DATA_ROWS / LOAD_CAPACITY)));

    return final;
}

void HashMap::addNode(string key, DrugData value)
{
    int hashValue = hashFunction(key);

    DrugData *newDrug = new DrugData;
    (*newDrug).mergeDrug(value);
    (*newDrug).pName = key;
    MapNode *newNode = new MapNode(key, newDrug);

    if (map[hashValue] == nullptr)
    {
        map[hashValue] = newNode;
    }
    else
    {
        MapNode *tempNode = map[hashValue];
        MapNode *prevNode = tempNode;
        while (tempNode != nullptr)
        {
            if((*tempNode).getKey() == key){
                (*(*tempNode).getValue()).mergeDrug(value);
                break;
            }
            prevNode = tempNode;
            tempNode = (*tempNode).getNextNode();
        }
        (*prevNode).setNextNode(newNode);
    }
}

void HashMap::deleteNode(string key)
{
    int hashValue = hashFunction(key);

    if (map[hashValue] != nullptr)
    {
        MapNode *tempNode = map[hashValue];
        MapNode *prevNode = tempNode;
        while (tempNode != nullptr)
        {
            if ((*tempNode).getKey() == key)
            {
                if (tempNode == prevNode)
                {
                    delete tempNode;
                    map[hashValue] = nullptr;
                }
                else
                {
                    (*prevNode).setNextNode((*tempNode).getNextNode());
                    delete tempNode;
                }
                break;
            }
            prevNode = tempNode;
            tempNode = (*tempNode).getNextNode();
        }
    }
}

DrugData *HashMap::getData(string key)
{
    int hashValue = hashFunction(key);

    if (map[hashValue] != nullptr)
    {
        MapNode *tempNode = map[hashValue];
        while (tempNode != nullptr)
        {
            if ((*tempNode).getKey() == key)
            {
                return (*tempNode).getValue();
            }
            tempNode = (*tempNode).getNextNode();
        }
        cout << "Not Found!" << endl;
        return nullptr;
    }
    else
    {
        cout << "Not Found!" << endl;
        return nullptr;
    }
}
