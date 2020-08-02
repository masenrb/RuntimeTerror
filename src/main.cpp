//
// Created by Masen Beliveau on 7/20/20.
//

#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>
#include"DrugData.h"

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
    using std::chrono::system_clock;

    PrintHeader();

    bool search = true;

    while (search) {
        std::string input;
        std::string drug;

        std::cout << "Would you like to search using an AVL Tree or a Map? (A/M) ";
        std::cin >> input;

        std::cout << "\nPlease type the name of the drug you are looking for: ";
        std::cin >> drug;

        int i = 0;
        int check = 0;
        cout<<"previous string: "<<drug<<endl;
        while(drug[i]){
            if(check==0){
                drug[i]=toupper(drug[i]);     //conversion of string takes place here
                check=1;
            }else if(isspace(drug[i]))       // change status of check if move to another word
                check=0;
            i++;
        }
        cout<<"Processed string: "<<drug<<endl;

        std::cout << std::endl << "Searching...\n" << std::endl;

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

        std::string presc = (drugData->prescription) ? "Yes" : "No";

        auto start = chrono::high_resolution_clock::now();

        bool found = true;
        //Search with either AVL or Map

        auto finish = chrono::high_resolution_clock::now();

        auto time = chrono::duration_cast<chrono::nanoseconds>(finish-start).count();

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
