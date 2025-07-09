#include "PhoneBook.hpp"
#include <iostream>
#include <limits>

PhoneBook::PhoneBook() : size(0), index(0) {}

void PhoneBook::addContact() {
    Contact newContact;
    if (!newContact.fillContact()) {
        std::cout << "All fields must be filled. Contact not saved." << std::endl;
        return;
    }

    contacts[index] = newContact;
    index = (index + 1) % 8;
    if (size < 8)
        size++;
    std::cout << "Contact added successfully!" << std::endl;
}

void PhoneBook::searchContact() const {
    if (size == 0) {
        std::cout << "Phonebook is empty." << std::endl;
        return;
    }

    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    for (int i = 0; i < size; ++i)
        contacts[i].displayShort(i);

    std::cout << "Enter index: ";
    int i;
    std::cin >> i;

    if (std::cin.fail() || i < 0 || i >= size) {
        std::cout << "Invalid index." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } else {
        std::cin.ignore();
        contacts[i].displayFull();
    }
}
