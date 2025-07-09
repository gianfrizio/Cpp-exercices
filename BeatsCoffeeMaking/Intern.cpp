#include "Intern.hpp"
#include <iostream>

// Costruttore, copia, distruttore

Intern::Intern() {}
Intern::Intern(const Intern& other) { (void)other; }
Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}
Intern::~Intern() {}

// Funzioni per creare i form concreti

AForm* Intern::createShrubbery(const std::string& target) const {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string& target) const {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(const std::string& target) const {
    return new PresidentialPardonForm(target);
}

// Funzione makeForm

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
    struct FormPair {
        std::string name;
        FormCreator creator;
    };

    FormPair forms[] = {
        { "shrubbery creation", &Intern::createShrubbery },
        { "robotomy request", &Intern::createRobotomy },
        { "presidential pardon", &Intern::createPresidential }
    };

    for (const auto& form : forms) {
        if (form.name == formName) {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*(form.creator))(target);
        }
    }

    std::cerr << "Intern couldn't create form: unknown form name '" << formName << "'" << std::endl;
    return nullptr;
}
