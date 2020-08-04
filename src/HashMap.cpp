#include "HashMap.h"
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

// Comstant variables that let us choose the load capacity and default number of rows for data input.
const float LOAD_CAPACITY = .67;
const int DEFAULT_NUM_ROWS = 100000;

//Node that store the data in each slot of the HashMap.
MapNode::MapNode(string key, DrugData *value)
{
    this->key = key;
    this->value = value;
    this->next = nullptr;
}

// The next 3 functions are accessors to MapNode variables.
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

// Sets the pointer to the next MapNode in case of a bucket in the HashMap.
void MapNode::setNextNode(MapNode *next)
{
    this->next = next;
}

// Default constructor for HashMap that uses default values.
HashMap::HashMap()
{
    map = vector<MapNode *>((int)(DEFAULT_NUM_ROWS / LOAD_CAPACITY), nullptr);
    numRows = DEFAULT_NUM_ROWS;
}

// This constructor allows to set a good size for the HashMap to cause minimal conflicts.
HashMap::HashMap(int dataSize)
{
    map = vector<MapNode *>((int)(dataSize / LOAD_CAPACITY), nullptr);
    numRows = dataSize;
}

// Destructor that loops through each HasMap slot and loops through each bucket to delete all pointers to MapNodes.
HashMap::~HashMap()
{
    for (int i = 0; i < map.size(); i++)
    {
        // Skips slots where no DrugData is stored.
        if (map[i] != nullptr)
        {
            MapNode *nextNode = map[i];
            while (nextNode != nullptr)
            {
                // prevNode allows to us to go back one step since buckets act as a singly linked list.
                MapNode *prevNode = nextNode;
                nextNode = (*nextNode).getNextNode();
                delete (*prevNode).getValue();
                delete prevNode;
            }
        }
    }
}

// Hashing function that attempts to turn every string input into a unique Hash Value.
int HashMap::hashFunction(string key)
{
    // The value 31 for the power variable is a common value for good string hashing functions.
    const int power = 31;

    // Variables that will store values for calculations.
    int counter = 0;
    long long hashValue = 0;

    // Loops through each character.
    for (char c : key)
    {
        // We take the character's number value and multiply it to the power variable raised to a power 
        // based on the location of the character.
        hashValue = hashValue + c * pow(power, counter);
        counter++;
    }
    
    // We turn the final value to a positive number because it will be used as an index that cannot be negative.
    // We also use modulo to limit the value to the range of the map vector to prevent out of bounds errors.
    int final = abs(hashValue % ((int)(numRows / LOAD_CAPACITY)));

    return final;
}

// Adds node to HashMap using a key and a DrugData object.
void HashMap::addNode(DrugData value)
{
    int hashValue = hashFunction(value.pName);

    // We create a new DrugData pointer to not point to the DrugData passed in which is on the stack.
    DrugData *newDrug = new DrugData;

    // The function mergeDrug and the assignment of key to pName both act as a copy contructor to the DrugData object.
    (*newDrug).mergeDrug(value);
    (*newDrug).pName = value.pName;

    // We create a MapNode before inputting into the HashMap.
    MapNode *newNode = new MapNode(value.pName, newDrug);

    // If there is no DrugData at this index, we add the MapNode just created.
    if (map[hashValue] == nullptr)
    {
        map[hashValue] = newNode;
    }
    else
    {
        MapNode *tempNode = map[hashValue];
        MapNode *prevNode = tempNode;
        bool merged = false;

        // If there is a DrugData at the index, we loop through the bucket.
        while (tempNode != nullptr)
        {
            // If we find a Node with the same key, we merge our DrugData to the original one and break the loop.
            if ((*tempNode).getKey() == value.pName)
            {
                (*(*tempNode).getValue()).mergeDrug(value);
                merged = true;
                break;
            }
            
            // We set the pointers to the next iteration of the while loop/
            prevNode = tempNode;
            tempNode = (*tempNode).getNextNode();
        }

        // If the DrugData was not merged, we add the Node we created to the end of the bucket.
        if(!merged){
            (*prevNode).setNextNode(newNode);
        }
    }
}

// Deletes Node based on key input.
void HashMap::deleteNode(string key)
{
    int hashValue = hashFunction(key);

    // If the index (Hash Value) we are accessing leads to no MapNodes, we ignore it.
    if (map[hashValue] != nullptr)
    {
        // MapNode pointers to keep track of previous MapNodes since the bucket acts as a singly linked list.
        MapNode *tempNode = map[hashValue];
        MapNode *prevNode = tempNode;

        // Loops through bucket to find needed MapNode.
        while (tempNode != nullptr)
        {
            if ((*tempNode).getKey() == key)
            {
                // This indicates that the MapNode found is the first in the bucket.
                if (tempNode == prevNode)
                {
                    // We do not need to worry about the 'next' pointer of the previous MapNode.
                    delete tempNode;
                    map[hashValue] = nullptr;
                }
                else
                {
                    // In case the bucket has more than one MapNode, we set the previous MapNode's 'next' 
                    // pointer to the right 'next'.
                    (*prevNode).setNextNode((*tempNode).getNextNode());
                    delete tempNode;
                }

                // Since the MapNode was found, we can exit the loop.
                break;
            }

            // Sets up the pointers for the next loop iteration.
            prevNode = tempNode;
            tempNode = (*tempNode).getNextNode();
        }
    }
}

// Returns a pointer to a DrugData object found using a key input.
DrugData *HashMap::getData(string key)
{
    int hashValue = hashFunction(key);

    // Makes sure the index we are accessing has at least one MapNode.
    if (map[hashValue] != nullptr)
    {
        // Lets us loop through buckets to find the MapNode, regardless of bucket size.
        MapNode *tempNode = map[hashValue];
        while (tempNode != nullptr)
        {
            // If the key needed is found in the bucket, end the function by returning the DrugData.
            if ((*tempNode).getKey() == key)
            {
                return (*tempNode).getValue();
            }
            tempNode = (*tempNode).getNextNode();
        }

        // If the MapNode is not found in the bucket, we return a nullptr and a message.
        cout << "Not Found!" << endl;
        return nullptr;
    }

    // In the case where the key inputted leads to no MapNodes, we ignore the request and return a nullptr and a message.
    else
    {
        cout << "Not Found!" << endl;
        return nullptr;
    }
}
