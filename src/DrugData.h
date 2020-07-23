#include <vector>
#include <string>
using namespace std;

//Header for the class that holds drug name along with additional drug data.
struct DrugData
{
    string pName;         //Proprietary name
    string npName;        //Non-Proprietary names
    bool prescription;    //Requires Prescription
    vector<string> form;  //Dosage Form
    vector<string> route; //Approved Producers

    DrugData()
    {
        prescription = false;
    }

    void update_P_Name(string pName)
    {
        this->pName = pName;
    }

    void update_NP_Name(string npName)
    {
        this->npName = npName;
    }

    void updatePrescription(bool input)
    {
        prescription = input;
    }

    void addDosageForm(string dosage)
    {
        form.push_back(dosage);
    }

    void addRoute(string route)
    {
        this->route.push_back(route);
    }

    void printDrug()
    {
        cout << "Proprietary Name: " << pName << endl;
        cout << "Non Proprietary Name: " << npName << endl;

        if (prescription)
        {
            cout << "Prescription: "
                 << "Yes" << endl;
        }
        else
        {
            cout << "Prescription: "
                 << "No" << endl;
        }

        cout << "Dosage Form(s): ";
        for (int i = 0; i < form.size(); i++)
        {
            if (i != (form.size() - 1))
            {
                cout << form[i] << ", ";
            }
            else
            {
                cout << form[i] << endl;
            }
        }

        cout << "Route(s): ";
        for (int i = 0; i < route.size(); i++)
        {
            if (i != (route.size() - 1))
            {
                cout << route[i] << ", ";
            }
            else
            {
                cout << route[i] << endl;
            }
        }
    }

    void addData(vector<string> data, bool prescription){
        if(data.size() == 4){
            update_P_Name(data[0]);
            update_NP_Name(data[1]);
            addDosageForm(data[2]);
            addRoute(data[3]);
            updatePrescription(prescription);
        }
    }
};
