#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

public:
    Contact();
    void setField(const std::string& prompt, std::string& field);
    bool fillContact();
    void displayShort(int index) const;
    void displayFull() const;
    bool isEmpty() const;
};

#endif
