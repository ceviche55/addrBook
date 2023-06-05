#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "contacts.h"
using namespace std;

int main() {
    vector<contactCard> contactList;

    while (true) {
        int userChoice;
        cout << "Contact Book Menu\n\n";
        cout << "1. Add New Contact\n";
        cout << "2. Display All Contacts\n";
        cout << "3. Exit\n";

        cout << "Choice: ";
        cin >> userChoice;
        std::cout << "-----------" << std::endl;

        switch (userChoice) {
            case 1:
                contactList.push_back(newContact());
                break;
            case 2:
                printAllContacts(contactList);
                break;
        }

        if (userChoice != 2 && userChoice != 1) {break;}
    }

    return 0;
}
