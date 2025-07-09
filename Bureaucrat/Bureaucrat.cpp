#include "Bureaucrat.hpp"

// Implementazione eccezioni

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high exception";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low exception";
}

// Costruttore
Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {}

// Assignment operator (name è const, non cambia)
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        // name const non si può assegnare
        grade = other.grade;
    }
    return *this;
}

// Distruttore
Bureaucrat::~Bureaucrat() {}

// Getters
const std::string& Bureaucrat::getName() const {
    return name;
}

int Bureaucrat::getGrade() const {
    return grade;
}

// Incrementa grado (diminuisce valore)
void Bureaucrat::incrementGrade() {
    if (grade <= 1)
        throw GradeTooHighException();
    --grade;
}

// Decrementa grado (aumenta valore)
void Bureaucrat::decrementGrade() {
    if (grade >= 150)
        throw GradeTooLowException();
    ++grade;
}

// Overload operatore <<
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}
