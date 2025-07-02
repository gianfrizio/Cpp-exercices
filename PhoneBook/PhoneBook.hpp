#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
    Contact contacts[8];
    int nextIndex; 
    int size;      

public:
    PhoneBook();

    void addContact(const Contact& c);
    Contact getContact(int index) const;
    int getSize() const;
};

#endif
