#include "DrugData.h"
#include <iostream>
using namespace std;

void DrugData::mergeDrug(DrugData &drug){
    bool found = false;

    //Adds Non Proprietary Names that are not found in the destination drug.
    for(int i = 0; i < drug.npNames.size(); i++){
        for(int j = 0; j < this->npNames.size(); i++){
            if(drug.npNames[i] == this->npNames[i]){
                found = true;
            }
        }
        if(!found){
            this->npNames.push_back(drug.npNames[i]);
        }
    }

    // If either drug needs a presecription the merged one will too.
    if(this->prescription || drug.prescription){
        this->prescription = true;
    }

    //Adds Forms that are not found in the destination drug.
    found = false;

    for(int i = 0; i < drug.forms.size(); i++){
        for(int j = 0; j < this->forms.size(); i++){
            if(drug.forms[i] == this->forms[i]){
                found = true;
            }
        }
        if(!found){
            this->forms.push_back(drug.forms[i]);
        }
    }

    //Adds Routes that are not found in the destination drug.
    found = false;

    for(int i = 0; i < drug.routes.size(); i++){
        for(int j = 0; j < this->routes.size(); i++){
            if(drug.routes[i] == this->routes[i]){
                found = true;
            }
        }
        if(!found){
            this->routes.push_back(drug.routes[i]);
        }
    }

    //Adds Providers that are not found in the destination drug.
    found = false;

    for(int i = 0; i < drug.providers.size(); i++){
        for(int j = 0; j < this->providers.size(); i++){
            if(drug.providers[i] == this->providers[i]){
                found = true;
            }
        }
        if(!found){
            this->providers.push_back(drug.providers[i]);
        }
    }
}

void DrugData::printDrug()
    {
        cout << "Proprietary Name: " << pName << endl;
        cout << "Non-Proprietary Name(s): ";
        for (int i = 0; i < npNames.size(); i++)
        {
            if (i != (npNames.size() - 1))
            {
                cout << npNames[i] << ", ";
            }
            else
            {
                cout << npNames[i] << endl;
            }
        }

        if (prescription)
        {
            cout << "Prescription: Yes" << endl;
        }
        else
        {
            cout << "Prescription: No" << endl;
        }

        cout << "Dosage Form(s): ";
        for (int i = 0; i < forms.size(); i++)
        {
            if (i != (forms.size() - 1))
            {
                cout << forms[i] << ", ";
            }
            else
            {
                cout << forms[i] << endl;
            }
        }

        cout << "Route(s): ";
        for (int i = 0; i < routes.size(); i++)
        {
            if (i != (routes.size() - 1))
            {
                cout << routes[i] << ", ";
            }
            else
            {
                cout << routes[i] << endl;
            }
        }
    }
    