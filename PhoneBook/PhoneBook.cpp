#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
    : nextIndex(0), size(0) {}

void PhoneBook::addContact(const Contact& c) {
    contacts[nextIndex] = c;
    nextIndex = (nextIndex + 1) % 8;
    if (size < 8) ++size;
}

Contact PhoneBook::getContact(int index) const {
    if (index < 0 || index >= size)
        return Contact(); 
    return contacts[index];
}

int PhoneBook::getSize() const {
    return size;
}
