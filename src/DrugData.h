#include <vector>
#include <string>
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

    void printDrug()
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
};
