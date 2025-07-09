
#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>

class Intern {
public:
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();

    AForm* makeForm(const std::string& formName, const std::string& target) const;

private:
    typedef AForm* (Intern::*FormCreator)(const std::string& target) const;

    AForm* createShrubbery(const std::string& target) const;
    AForm* createRobotomy(const std::string& target) const;
    AForm* createPresidential(const std::string& target) const;
};

#endif
