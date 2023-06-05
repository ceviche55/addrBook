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
    name = "";
    nickName = "";
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
            "Name:\t";
    std::cin.ignore();
    getline(std::cin, name);
    std::cout << "Nickname:\t";
    std::cin >> nickname;
    std::cout << "Phone Number:\t";
    std::cin >> phoneNum;
    std::cout << "Notes:\t";
    std::cin.ignore();
    getline(std::cin, notes);
    std::cout << "----------" << std::endl;

    newContactCard.setName(name);
    newContactCard.setNickName(nickname);
    newContactCard.setPhoneNum(phoneNum);
    newContactCard.setNotes(notes);

    return newContactCard;
}

void printContacts(const contactCard& contCardRef) {
    std::cout << "Name: " << contCardRef.getName() << std::endl
        << "Nickname: " << contCardRef.getNickname() << std::endl
        << "Phone Number: " << contCardRef.getPhoneNum() << std::endl;
    if (contCardRef.getNotes() != "") {
        std::cout << "Notes: " << contCardRef.getNotes() << std::endl;
    }
}

void printAllContacts(const std::vector<contactCard> contactListRef) {
    std::cout << "Displaying all contacts:\n\n";
    for (contactCard elem: contactListRef) {
        printContacts(elem);
        std::cout << std::endl;
    }
    std::cout << "----------" << std::endl;
}
