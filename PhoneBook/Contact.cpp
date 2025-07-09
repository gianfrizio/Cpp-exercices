#include "Contact.hpp"
#include <iostream>
#include <iomanip>

Contact::Contact() {}

void Contact::setField(const std::string& prompt, std::string& field) {
    std::string input;
    std::cout << prompt;
    std::getline(std::cin, input);
    field = input;
}

bool Contact::fillContact() {
    setField("First Name: ", firstName);
    setField("Last Name: ", lastName);
    setField("Nickname: ", nickname);
    setField("Phone Number: ", phoneNumber);
    setField("Darkest Secret: ", darkestSecret);

    return !(firstName.empty() || lastName.empty() || nickname.empty() ||
             phoneNumber.empty() || darkestSecret.empty());
}

void Contact::displayShort(int index) const {
    auto format = [](const std::string& str) {
        if (str.length() > 10)
            return str.substr(0, 9) + ".";
        return str;
    };

    std::cout << "|" << std::setw(10) << index
              << "|" << std::setw(10) << format(firstName)
              << "|" << std::setw(10) << format(lastName)
              << "|" << std::setw(10) << format(nickname)
              << "|" << std::endl;
}

void Contact::displayFull() const {
    std::cout << "First Name: "     << firstName     << std::endl;
    std::cout << "Last Name: "      << lastName      << std::endl;
    std::cout << "Nickname: "       << nickname      << std::endl;
    std::cout << "Phone Number: "   << phoneNumber   << std::endl;
    std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}

bool Contact::isEmpty() const {
    return firstName.empty();
}
