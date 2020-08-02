#include "CSV_Import.h"
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

    // Counter lets us know which data value we are currently on.
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
                    drug.prescription = true;
                }
                else
                {
                    drug.prescription = false;
                }
                break;
            }
            // Handles Proprietary Name.
            case 2:
            {
                transform(curData.begin(), curData.end(), curData.begin(), ::toupper);
                drug.pName = curData;
                break;
            }
            // Handles Non Proprietary Name.
            case 3:
            {
                drug.npNames.push_back(curData);
                break;
            }
            // Handles all Dosage Forms.
            case 4:
            {
                stringstream dosageStream(curData);
                string curDosage;
                while (getline(dosageStream, curDosage, '-'))
                {
                    drug.forms.push_back(curDosage);
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
                    drug.routes.push_back(curRoute);
                }
                break;
            }
            // Handles all Providers.
            case 6:
            {
                drug.providers.push_back(curData);
                break;
            }
            }
            counter++;
        }
        final.push_back(drug);
    }
    final.erase(final.begin());
    return final;
}
