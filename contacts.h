#ifndef CONTACTS_H
#define CONTACTS_H

#include <iostream>
#include <ostream>
#include <string>
#include <vector>

class contactCard {
    private:
        std::string name;
        std::string nickName;
        long phoneNum;
        std::string notes;

    public:
        std::string getName() const;
        std::string getNickname() const;
        long getPhoneNum() const;
        std::string getNotes() const;

        void setName(std::string newName);
        void setNickName(std::string newNickName);
        void setPhoneNum(long newPhoneNum);
        void setNotes(std::string newNotes);

        contactCard();
};

contactCard newContact();
void printContact(const contactCard& contCardRef);
void printAllContacts(const std::vector<contactCard> contactListRef);
void deleteContactFromList(std::vector<contactCard> &contactListRef);
bool searchContact(std::vector<contactCard> &contactListRef);
void changeContactDetails(contactCard& contCardRef);
void updateContact(std::vector<contactCard> &contactListRef);
bool sortContact(std::vector<contactCard> &contactListRef);

#endif
