#include<vector>
#include<string>

//Header for the class that holds drug name along with additional drug data.
struct DrugData
{
    std::string pName;                  //Proprietary name
    std::string npName;                 //Non-Proprietary names
    bool perscription;                  //Requires Prescription
    std::vector<std::string> form;      //Dosage Form
    std::vector<std::string> route;     //Approved Producers
};
