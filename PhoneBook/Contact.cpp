#include "Contact.hpp"

Contact::Contact()
    : firstName(""), lastName(""), phoneNumber("") {}

void Contact::setFirstName(const std::string& fn) {
    firstName = fn;
}

void Contact::setLastName(const std::string& ln) {
    lastName = ln;
}

void Contact::setPhoneNumber(const std::string& pn) {
    phoneNumber = pn;
}

std::string Contact::getFirstName() const {
    return firstName;
}

std::string Contact::getLastName() const {
    return lastName;
}

std::string Contact::getPhoneNumber() const {
    return phoneNumber;
}

bool Contact::isEmpty() const {
    return firstName.empty() && lastName.empty() && phoneNumber.empty();
}
