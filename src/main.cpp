//
// Created by Masen Beliveau on 7/20/20.
//

#include <iostream>

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

        //Will add timestamp here (TEMP)
        int time = 100;

        bool found = true;
        //Search with either AVL or Map

        if (found) {
            std::cout << "Found! Time needed : " << time << " seconds.\n" << std::endl;

            std::cout << "------------------------------------------------------------------------------\n"
                         "\n"
                         "Proprietary name:   \t\tAdvil\n"
                         "Non-Proprietary names: \t\tIbuprofen\n"
                         "\t\t\t\t\t\t\tIbuprofen Sodium\n"
                         "Requires Prescription:\t\tNo\n"
                         "Dosage Form:\t\t\t\tCoated Tablet\n"
                         "Route:\t\t\t\t\t\tOral\n"
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
