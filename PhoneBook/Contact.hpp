#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
private:
    std::string firstName;
    std::string lastName;
    std::string phoneNumber;

public:
    Contact();
    void setFirstName(const std::string& fn);
    void setLastName(const std::string& ln);
    void setPhoneNumber(const std::string& pn);

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getPhoneNumber() const;

    bool isEmpty() const; 
};

#endif
