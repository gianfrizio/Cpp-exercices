#include "AForm.hpp"
#include "Bureaucrat.hpp"

const char* AForm::GradeTooHighException::what() const throw() {
    return "AForm grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "AForm grade too low";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "AForm not signed";
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExec, const std::string& target)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExec(gradeToExec), target(target) {
    if (gradeToSign < 1 || gradeToExec < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExec > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
    : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign),
      gradeToExec(other.gradeToExec), target(other.target) {}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        isSigned = other.isSigned;
    }
    return *this;
}

AForm::~AForm() {}

const std::string& AForm::getName() const { return name; }
bool AForm::getIsSigned() const { return isSigned; }
int AForm::getGradeToSign() const { return gradeToSign; }
int AForm::getGradeToExec() const { return gradeToExec; }
const std::string& AForm::getTarget() const { return target; }

void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}

void AForm::execute(Bureaucrat const & executor) const {
    if (!isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > gradeToExec)
        throw GradeTooLowException();
    action();
}

std::ostream& operator<<(std::ostream& os, const AForm& f) {
    os << "Form " << f.getName() << " [signed: " << (f.getIsSigned() ? "yes" : "no")
       << ", grade to sign: " << f.getGradeToSign()
       << ", grade to exec: " << f.getGradeToExec()
       << ", target: " << f.getTarget() << "]";
    return os;
}
