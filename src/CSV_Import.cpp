#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>
#include <sstream>
#include "DrugData.h"
using namespace std;

vector<DrugData> csvToMap(string filename)
{
    ifstream dataFile(filename);

    // Returns an error if file cannot be opened.
    if (!dataFile.is_open())
    {
        throw runtime_error("Data file could not be opened.");
    }

    vector<DrugData> final;
    string line, curData;

    // first makes sure to update prescription in the first iteration of the string stream bellow.
    bool prescription, first;       

    // Reads every line in the CSV file.
    while (getline(dataFile, line))
    {
        stringstream lineStream(line);
        
        // Will store drug data required for the addData function.
        vector<string> lineData;
        DrugData drug;

        // Reads every element of the CSV line.
        first = true;
        while (getline(lineStream, curData, ','))
        {
            if(first){
                if (curData == "HUMAN PRESCRIPTION DRUG"){
                    prescription = true;
                }else{
                    prescription = false;
                }
                first = false;
            }else{
                lineData.push_back(curData);
            }
        }

        drug.addData(lineData, prescription);
        final.push_back(drug);
    }
    return final;
}

int main()
{
    vector<DrugData> output;
    output = csvToMap("../RawData/Drugs_product(Shortened).csv");

    // Outputs formatted data.
    for (int i = 0; i < output.size(); i++)
    {
        output[i].printDrug();
    }
    return 0;
};
