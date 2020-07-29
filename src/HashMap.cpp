#include "HashMap.h"
#include <math.h>

const float LOAD_CAPACITY = .67;
const int NUM_DATA_ROWS = 115138;

MapNode::MapNode(string key, DrugData value){
    this->key = key;
    this->value = value;
    this->next = NULL;
}

string MapNode::getKey(){
    return key;
}

DrugData MapNode::getValue(){
    return value;
}

MapNode *MapNode::getNextNode(){
    return next;
}

void MapNode::setNextNode(MapNode *next){
    this->next = next;
}

void MapNode::setValue(DrugData value){
    this->value = value;
}

HashMap::HashMap(int numDataRows, float loadCapacity){
    map = vector<MapNode*>( (int) (numDataRows / loadCapacity), NULL);
}

HashMap::~HashMap(){
    for(int i = 0; i < map.size(); i++){
        if(map[i] != NULL){
            MapNode *nextNode = map[i];
            while(nextNode != NULL){
                MapNode *prevNode = nextNode;
                nextNode = (*nextNode).getNextNode();
                delete prevNode;
            }
        }
    }
}

int HashMap::hashFunction(string key){
    const int power = 31;
    int counter = 0;
    long hashValue = 0;
    for (char c : key){
        hashValue = hashValue + (c - 'a' + 1) * pow(power, counter);
        counter++;
    }

    return hashValue % ((int) (NUM_DATA_ROWS/LOAD_CAPACITY));
}

void HashMap::addNode(string key, DrugData value){
    int hashValue = hashFunction(key);

    MapNode *newNode = new MapNode(key, value);

    if(map[hashValue] == NULL){
        map[hashValue] = newNode;
    }else{
        MapNode *tempNode = map[hashValue];
        while((*tempNode).getNextNode() != NULL && (*(*tempNode).getNextNode()).getKey() != key){
            tempNode = (*tempNode).getNextNode();
        }
        if((*tempNode).getNextNode() == NULL){
            (*tempNode).setNextNode(newNode);
        }else{
            MapNode *initialNode = (*tempNode).getNextNode();
            (*initialNode).getValue().mergeDrug(value);
        }
    }
}