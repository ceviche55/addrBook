#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "contacts.h"
using namespace std;

int main() {
    vector<contactCard> contactList;

    contactCard tempContCard;
    tempContCard.setName("Khalid Hamu");
    tempContCard.setNickName("Kade");
    tempContCard.setPhoneNum(1234567890);
    tempContCard.setNotes("Coffee lover");
    contactList.push_back(tempContCard);

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
                printAllContacts(contactList);
                break;
            case 3:
                deleteContact(contactList);
                break;
            case 4:
                if (!searchContact(contactList)) {
                    cout << "\t\nNo Contact Found\n";
                }
                break;
            default:
                cout << "\nNow Exiting.";
                return 0;
                break;
        }
    }
    return 0;
}
