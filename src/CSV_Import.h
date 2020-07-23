#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>
#include <sstream>
#include "DrugData.h"
using namespace std;

vector<DrugData> csvToDrugData(string filename)
{
    ifstream dataFile(filename);

    // Returns an error if file cannot be opened.
    if (!dataFile.is_open())
    {
        throw runtime_error("Data file could not be opened.");
    }

    vector<DrugData> final;
    string line, curData;

    // Counter lets us know which data value we are currenlty on.
    bool prescription;
    int counter;

    // Reads every line in the CSV file.
    while (getline(dataFile, line))
    {
        // Sets up variables we will be needing to store the data.
        stringstream lineStream(line);
        DrugData drug;

        // Resets on every loop.
        counter = 1;

        // Reads every element of the CSV line.
        while (getline(lineStream, curData, ','))
        {
            switch (counter)
            {
            // Handles Prescription value.
            case 1:
            {
                if (curData == "HUMAN PRESCRIPTION DRUG")
                {
                    drug.updatePrescription(true);
                }
                else
                {
                    drug.updatePrescription(false);
                }
                break;
            }
            // Handles Proprietary Name.
            case 2:
            {
                drug.update_P_Name(curData);
                break;
            }
            // Handles Non Proprietary Name.
            case 3:
            {
                drug.update_NP_Name(curData);
                break;
            }
            // Handles all Dosage Forms.
            case 4:
            {
                stringstream dosageStream(curData);
                string curDosage;
                while (getline(dosageStream, curDosage, '-'))
                {
                    drug.addDosageForm(curDosage);
                }
                break;
            }
            // Handles all Routes.
            case 5:
            {
                stringstream routeStream(curData);
                string curRoute;
                while (getline(routeStream, curRoute, '-'))
                {
                    drug.addRoute(curRoute);
                }
                break;
            }
            }
            counter++;
        }
        final.push_back(drug);
    }
    return final;
}
