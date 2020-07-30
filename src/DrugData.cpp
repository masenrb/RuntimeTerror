#include "DrugData.h"
#include <iostream>
using namespace std;

void DrugData::mergeDrug(DrugData &drug){
    bool found = false;

    //Adds Non Proprietary Names that are not found in the destination drug.
    for(auto & npName : drug.npNames){
        for(auto & j : this->npNames){
            if(npName == j){
                found = true;
            }
        }
        if(!found){
            this->npNames.push_back(npName);
        }
    }

    // If either drug needs a prescription the merged one will too.
    if(this->prescription || drug.prescription){
        this->prescription = true;
    }

    //Adds Forms that are not found in the destination drug.
    found = false;

    for(auto & form : drug.forms){
        for(auto & j : this->forms){
            if(form == j){
                found = true;
            }
        }
        if(!found){
            this->forms.push_back(form);
        }
    }

    //Adds Routes that are not found in the destination drug.
    found = false;

    for(auto & route : drug.routes){
        for(auto & j : this->routes){
            if(route == j){
                found = true;
            }
        }
        if(!found){
            this->routes.push_back(route);
        }
    }

    //Adds Providers that are not found in the destination drug.
    found = false;

    for(auto & provider : drug.providers){
        for(auto & j : this->providers){
            if(provider == j){
                found = true;
            }
        }
        if(!found){
            this->providers.push_back(provider);
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
    