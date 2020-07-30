//
// Created by Masen Beliveau on 7/20/20.
//

#include <iostream>
#include <iomanip>
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

    PrintHeader();

    bool search = true;

    while (search) {
        std::string input;
        std::string drug;

        std::cout << "Would you like to search using an AVL Tree or a Map? (A/M) ";
        std::cin >> input;

        std::cout << "\nPlease type the name of the drug you are looking for: ";
        std::cin >> drug;

        std::cout << std::endl << "Searching...\n" << std::endl;

        DrugData *drugData = new DrugData();
        drugData->pName = "Advil";
        drugData->npName = "Ibuprofen";
        drugData->prescription = false;
        drugData->form.push_back("Coated Tablet");
        drugData->form.push_back("Liquid Gel");
        drugData->form.push_back("Shot");
        drugData->route.push_back("Oral");
        drugData->route.push_back("Syringe");

        std::string presc = (drugData->prescription) ? "Yes" : "No";

        //Will add timestamp here (TEMP)
        int time = 100;

        bool found = true;
        //Search with either AVL or Map

        if (found) {
            std::cout << "Found! Time needed : " << time << " seconds.\n" << std::endl;

            std::cout << "------------------------------------------------------------------------------\n"
                         "\n"
                         << std::setw(28) << left << "Proprietary name:" << drugData->pName << "\n"
                         << std::setw(28) << left << "Non-Proprietary names:" << drugData->npName << "\n"
                         << std::setw(28) << left << "" << "Ibuprofen Sodium\n"
                         << std::setw(28) << left << "Requires Prescription:" << presc << "\n"
                         << std::setw(28) << left << "Dosage Form:";
                            for (int i = 0; i < drugData->form.size(); i++)
                            {
                                if (i != (drugData->form.size() - 1))
                                {
                                    cout << drugData->form[i] << endl << std::setw(28) << left << "";
                                }
                                else
                                {
                                    cout << drugData->form[i] << endl;
                                }
                            }
            std::cout <<
                        std::setw(28) << left <<"Route:";
                            for (int i = 0; i < drugData->route.size(); i++)
                            {
                                if (i != (drugData->route.size() - 1))
                                {
                                    cout << drugData->route[i] << endl << std::setw(28) << left << "";
                                }
                                else
                                {
                                    cout << drugData->route[i] << endl;
                                }
                            }
            std::cout <<
                         "Approved Producers:\t\t\tPfizer Consumer Healthcare\t\n"
                         "\n"
                         "------------------------------------------------------------------------------\n" << std::endl;
        } else {
            std::cout << "Not Found. Time needed : " << time << " seconds." << std::endl;
        }

        std::cout << "Search Again? (Y/N) ";
        std::cin >> input;

        std::cout << std::endl;

        if (input == "N") {
            search = false;
        }
    }

    return 0;
}
