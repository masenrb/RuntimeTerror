#include <iostream>
#include <iomanip>
#include <chrono>
#include"DrugData.h"
#include "CSV_Import.h"
#include "HashMap.h"
#include "AVLTree.h"

void PrintHeader() {
    std::cout << "-------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;

    std::cout << " _______  _______       ___          _______  .______       __    __    _______     _______  __  .__   __.  _______   _______ .______      \n"
                 "|   ____||       \\     /   \\        |       \\ |   _  \\     |  |  |  |  /  _____|   |   ____||  | |  \\ |  | |       \\ |   ____||   _  \\     \n"
                 "|  |__   |  .--.  |   /  ^  \\       |  .--.  ||  |_)  |    |  |  |  | |  |  __     |  |__   |  | |   \\|  | |  .--.  ||  |__   |  |_)  |    \n"
                 "|   __|  |  |  |  |  /  /_\\  \\      |  |  |  ||      /     |  |  |  | |  | |_ |    |   __|  |  | |  . `  | |  |  |  ||   __|  |      /     \n"
                 "|  |     |  '--'  | /  _____  \\     |  '--'  ||  |\\  \\----.|  `--'  | |  |__| |    |  |     |  | |  |\\   | |  '--'  ||  |____ |  |\\  \\----.\n"
                 "|__|     |_______/ /__/     \\__\\    |_______/ | _| `._____| \\______/   \\______|    |__|     |__| |__| \\__| |_______/ |_______|| _| `._____|\n" << std::endl;

    std::cout << "\nThis program allows you to find a summary of all the information related to a drug using FDA Data\n" << std::endl;
}

int main() {
    //To get timestamps
    using std::chrono::system_clock;

    PrintHeader();

    cout << "Loading data..." << endl;

    vector<DrugData> drugs = csvToDrugData("../RawData/Drugs_product(Shortened).csv");
    HashMap drugs_hash;
    AVLTree drugs_avl;

    for (int i = 0; i < drugs.size(); i++) {
        drugs_hash.addNode(drugs[i].pName, drugs[i]);
        drugs_avl.insert(drugs[i]);
        if (i == 0.25 * drugs.size()) {
            cout << "25%\n";
        }
        if (i == 0.5 * drugs.size()) {
            cout << "50%\n";
        }
        if (i == 0.75 * drugs.size()) {
            cout << "75%\n";
        }
        if (i == drugs.size() - 1) {
            cout << "100%\n" << endl;
        }
    }

    bool search = true;

    //Loop until the user no longer wants to search
    while (search) {
        std::string input;
        std::string drug;

        bool correctSearch = true;

        //Search guard to make sure input is A or M
        while(correctSearch) {
            std::cout << "Would you like to search using an AVL Tree or a Map? (A/M) ";
            std::cin >> input;
            input = ::toupper(input[0]);
            if (input != "A" and input != "M") {
                cout << "\nInvalid input, please enter A or M\n" << endl;
                continue;
            } else {
                correctSearch = false;
            }
        }
        cin.get();

        std::cout << endl << "Please type the name of the drug you are looking for: ";
        getline(cin, drug);

        //Makes drug input string capitalized for string comparison
        transform(drug.begin(), drug.end(), drug.begin(), ::toupper);

        std::cout << std::endl << "Searching...\n" << std::endl;

        //TEMPORARY
        //REMOVE AFTER IMPLEMENTING SEARCH
        DrugData *drugData = new DrugData();
        drugData->pName = "Advil";
        drugData->npNames.push_back("Ibuprofen");
        drugData->npNames.push_back("Ibuprofen MAXIMUM HEADACHE RELIEF");
        drugData->prescription = false;
        drugData->forms.push_back("Coated Tablet");
        drugData->forms.push_back("Liquid Gel");
        drugData->forms.push_back("Shot");
        drugData->routes.push_back("Oral");
        drugData->routes.push_back("Syringe");

        //If statement to say if drug needs prescription or not dependent on bool
        std::string presc = (drugData->prescription) ? "Yes" : "No";

        //Start clock before search
        auto start = chrono::high_resolution_clock::now();

        bool found = true;
        //Search with either AVL or Map

        //End clock after search finished
        auto finish = chrono::high_resolution_clock::now();

        auto time = chrono::duration_cast<chrono::nanoseconds>(finish-start).count();

        //If the drug exists in system
        if (found) {
            std::cout << "Found! Time needed: " << time << " nanoseconds.\n" << std::endl;

            std::cout << "------------------------------------------------------------------------------\n"
                         "\n"
                      << std::setw(28) << left << "Proprietary name:" << drugData->pName << "\n"
                      << std::setw(28) << left << "Non-Proprietary names:";
            for (int i = 0; i < drugData->npNames.size(); i++)
            {
                if (i != (drugData->npNames.size() - 1))
                {
                    cout << drugData->npNames[i] << endl << std::setw(28) << left << "";
                }
                else
                {
                    cout << drugData->npNames[i] << endl;
                }
            }
            cout << std::setw(28) << left << "Requires Prescription:" << presc << "\n"
                 << std::setw(28) << left << "Dosage forms:";
            for (int i = 0; i < drugData->forms.size(); i++)
            {
                if (i != (drugData->forms.size() - 1))
                {
                    cout << drugData->forms[i] << endl << std::setw(28) << left << "";
                }
                else
                {
                    cout << drugData->forms[i] << endl;
                }
            }
            std::cout <<
                      std::setw(28) << left <<"Route:";
            for (int i = 0; i < drugData->routes.size(); i++)
            {
                if (i != (drugData->routes.size() - 1))
                {
                    cout << drugData->routes[i] << endl << std::setw(28) << left << "";
                }
                else
                {
                    cout << drugData->routes[i] << endl;
                }
            }
            std::cout <<
                      "Approved Producers:\t\t\tPfizer Consumer Healthcare\t\n"
                      "\n"
                      "------------------------------------------------------------------------------\n" << std::endl;
        } else {
            std::cout << "Not Found. Time needed : " << time << " seconds." << std::endl;
        }

        bool response = true;

        //Search guard to make sure input is Y or N
        while (response) {
            std::cout << "Search Again? (Y/N) ";
            std::cin >> input;

            std::cout << std::endl;
            if (input == "Y") {
                response = false;
            } else if (input == "N") {
                response = false;
                search = false;
            } else {
                cout << "Incorrect input, please try again.\n" << endl;
            }
        }
    }

    return 0;
}
