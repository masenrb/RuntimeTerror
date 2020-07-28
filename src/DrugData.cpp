#include "DrugData.h"
using namespace std;

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