#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>
#include <sstream>
using namespace std;

vector< vector<string> > csvToMap(string filename)
{
    ifstream dataFile(filename);

    // Returns an error if file cannot be opened.
    if (!dataFile.is_open())
    {
        throw runtime_error("Data file could not be opened.");
    }

    vector< vector<string> > final;
    string line;
    string curData;

    // Reads every line in the CSV file.
    while (getline(dataFile, line))
    {
        stringstream lineStream(line);
        vector<string> lineData;

        // Reads every element of the CSV line.
        while (getline(lineStream, curData, ','))
        {
            lineData.push_back(curData);
        }

        final.push_back(lineData);
    }
    return final;
}

int main()
{
    vector< vector<string> > output;
    output = csvToMap("../RawData/Drugs_product (Shortened).csv");

    // Outputs formatted data.
    for (int i = 0; i < output.size(); i++)
    {
        for (int j = 0; j < output[i].size(); j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
};