#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat {
private:
    const std::string name;
    int grade; // 1 = highest, 150 = lowest

public:
    // Eccezioni
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    // Costruttore, copy constructor, operator=, destructor
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    // Getters
    const std::string& getName() const;
    int getGrade() const;

    // Incrementa e decrementa grado
    void incrementGrade(); // diminuisce il valore numerico del grado (es. 3 -> 2)
    void decrementGrade(); // aumenta il valore numerico del grado (es. 2 -> 3)
};

// Overload operatore <<
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
