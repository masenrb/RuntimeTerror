#pragma once
#include <vector>
#include <string>
#include <iostream>
using namespace std;

//Header for the class that holds drug name along with additional drug data.
struct DrugData
{
    string pName;                    //Proprietary name
    vector<string> npNames;          //Non-Proprietary names
    bool prescription;               //Requires Prescription
    vector<string> forms;            //Dosage Form
    vector<string> routes;           //Routes
    vector<string> providers;        //Approved Producers

    DrugData();
    void mergeDrug(DrugData &drug);
    void printDrug();
};
