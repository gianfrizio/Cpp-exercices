#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExec;
    const std::string target;

public:
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };
    class FormNotSignedException : public std::exception {
    public:
        const char* what() const throw();
    };

    AForm(const std::string& name, int gradeToSign, int gradeToExec, const std::string& target);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    const std::string& getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExec() const;
    const std::string& getTarget() const;

    void beSigned(const Bureaucrat& b);

    virtual void execute(Bureaucrat const & executor) const;

protected:
    virtual void action() const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
