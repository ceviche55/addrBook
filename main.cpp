#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "contacts.h"
using namespace std;

int main() {
    vector<contactCard> contactList;

    // Section for Importing Contacts from database file
    fstream contactCsv("Database.csv");
    string line, cell;

    getline(contactCsv, line);
    
    while (getline(contactCsv, line)) {
        stringstream sSLine(line);
        contactCard tempContCard;

        getline(sSLine, cell, ',');
        tempContCard.setName(cell);
        
        getline(sSLine, cell, ',');
        tempContCard.setNickName(cell);

        getline(sSLine, cell, ',');
        tempContCard.setPhoneNum(stol(cell));

        getline(sSLine, cell, ',');
        tempContCard.setNotes(cell);

        contactList.push_back(tempContCard);
    }

    while (true) {
        int userChoice;
        cout << "Contact Book Menu\n\n";
        cout << "\t1. Add New Contact\n";
        cout << "\t2. Display All Contacts\n";
        cout << "\t3. Delete Contact(s)\n";
        cout << "\t4. Search Contacts\n";
        cout << "\t0. Exit\n";

        cout << "\n\tChoice: ";
        cin >> userChoice;
        std::cout << "-----------" << std::endl;

        switch (userChoice) {
            case 1:
                contactList.push_back(newContact());
                break;
            case 2:
                if (!sortContact(contactList)) {cout << "Contacts not Sorted\n";}
                printAllContacts(contactList);
                break;
            case 3:
                deleteContactFromList(contactList);
                break;
            case 4:
                if (!searchContact(contactList)) {cout << "\t\nNo Contact Found\n";}
                break;
            default:
                cout << "\nNow Exiting.";
                return 0;
                break;
        }
    }
    return 0;
}
