#include <iostream>
#include "PhoneBook.hpp"

int main() {
    PhoneBook phonebook;
    Contact c1;
    c1.setFirstName("Mario");
    c1.setLastName("Rossi");
    c1.setPhoneNumber("1234567890");

    phonebook.addContact(c1);
    for (int i = 0; i < phonebook.getSize(); ++i) {
        Contact c = phonebook.getContact(i);
        std::cout << i + 1 << ": " << c.getFirstName() << " "
                  << c.getLastName() << " - " << c.getPhoneNumber() << "\n";
    }

    return 0;
}
