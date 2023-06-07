#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include "contacts.h"

std::string contactCard::getName() const {return name;}
std::string contactCard::getNickname() const {return nickName;}
long contactCard::getPhoneNum() const {return phoneNum;}
std::string contactCard::getNotes() const {return notes;}

void contactCard::setName(std::string newName) {name = newName;}
void contactCard::setNickName(std::string newNickName) {nickName = newNickName;}
void contactCard::setPhoneNum(long newPhoneNum) {phoneNum = newPhoneNum;}
void contactCard::setNotes(std::string newNotes) {notes = newNotes;}

contactCard::contactCard() {
    name = "NAN";
    nickName = "NAN";
    phoneNum = 0000000000;
    notes = "";
}

contactCard newContact() {
    contactCard newContactCard;
    
    std::string name;
    std::string nickname;
    long phoneNum;
    std::string notes;

    std::cout << "New Contact Information\n\n" <<
            "\tName:\t";
    std::cin.ignore();
    getline(std::cin, name);
    std::cout << "\tNickname:\t";
    std::cin >> nickname;
    std::cout << "\tPhone Number:\t";
    std::cin >> phoneNum;
    std::cout << "\tNotes:\t";
    std::cin.ignore();
    getline(std::cin, notes);
    std::cout << "----------" << std::endl;

    newContactCard.setName(name);
    newContactCard.setNickName(nickname);
    newContactCard.setPhoneNum(phoneNum);
    newContactCard.setNotes(notes);

    return newContactCard;
}

void printContact(const contactCard& contCardRef) {
    std::cout << "\tName: " << contCardRef.getName() << std::endl
        << "\tNickname: " << contCardRef.getNickname() << std::endl
        << "\tPhone Number: " << contCardRef.getPhoneNum() << std::endl;
    if (contCardRef.getNotes() != "") {
        std::cout << "\tNotes: " << contCardRef.getNotes() << std::endl;
    }
}

void printAllContacts(const std::vector<contactCard> contactListRef) {
    std::cout << "Displaying all contacts:\n\n";
    for (contactCard elem: contactListRef) {
        printContact(elem);
        std::cout << std::endl;
    }
    std::cout << "----------" << std::endl;
}

void deleteContact(std::vector<contactCard> &contactListRef) {
    char userChoice;
    std::cout << "Contact Deletion:\n\n";
    for (int i = 0; i < contactListRef.size(); i++) {
        printContact(contactListRef[i]);
        std::cout << std::endl;

        std::cout << "Do you want to delete this contact (Y or N)? ";
        std::cin >> userChoice;
        
        switch (userChoice) {
            case 'y':
            case 'Y':
               contactListRef.erase(contactListRef.begin() + i);
               break;
            default:
               break;
        }
    }
    std::cout << "----------" << std::endl;
    
}

void changeContactDetails(contactCard& contCardRef) {
    char userChoice;
    std::string newString;
    long newLong;

    printContact(contCardRef);

    std::cout << std::endl << "\t\tChange Name (Y or N)? ";
    std::cin >> userChoice;

    switch (userChoice) {
    case 'y':
    case 'Y':
        std::cout << "\t\tNew Name:\t";
        std::cin.ignore();
        std::getline(std::cin, newString);
        contCardRef.setName(newString);
        break;
    default:
        break;
    }
}

void updateContact(std::vector<contactCard> &contactListRef) {
    char userChoice;
    std::cout << "Contact Deletion:\n\n";
    for (int i = 0; i < contactListRef.size(); i++) {
        printContact(contactListRef[i]);
        std::cout << std::endl;

        std::cout << "\tDo you want to update this contact (Y or N)? ";
        std::cin >> userChoice;
        
        switch (userChoice) {
            case 'y':
            case 'Y':
                changeContactDetails(contactListRef[i]);
               break;
            default:
               break;
        }
    }
    std::cout << "----------" << std::endl;
    
}

void searchContact(std::vector<contactCard> &contactListRef) {
    int userChoice;
    std::string userSearch;

    std::cout << "Contact Search:\n";
    std::cout << "Pick field to search\n";

    std::cout << "\t1. Name\n";
    std::cout << "\t2. Nickname\n";
    std::cout << "\t3. Phone Number\n";
    std::cout << "\n\tChoice:\t";
    std::cin >> userChoice;

    std::cout << "\n\n\tSearch (exact):\t";
    std::cin.ignore();
    std::getline(std::cin, userSearch);

    for (contactCard elem : contactListRef) {
        switch (userChoice) {
            case 1:
               if (elem.getName() == userSearch) {
                 printContact(elem);
               }
               break;
            case 2:
               if (elem.getNickname() == userSearch) {
                 printContact(elem);
               }
               break;
            case 3:
               if (std::to_string(elem.getPhoneNum()) == userSearch) {
                 printContact(elem);
               }
               break;
            default:
                std::cout << "\n\tInvalid Choice!\n";
        }
    }
}
