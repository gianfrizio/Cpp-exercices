#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    Intern intern;
    Bureaucrat bob("Bob", 1);
    Bureaucrat alice("Alice", 140);
    Bureaucrat jim("Jim", 150);

    AForm* form1 = intern.makeForm("shrubbery creation", "Garden");
    AForm* form2 = intern.makeForm("robotomy request", "Bender");
    AForm* form3 = intern.makeForm("presidential pardon", "Marvin");
    AForm* form4 = intern.makeForm("invalid form", "Nobody");

    std::cout << "\n-- Forms created --\n";
    if (form1) std::cout << *form1 << std::endl;
    if (form2) std::cout << *form2 << std::endl;
    if (form3) std::cout << *form3 << std::endl;

    // Try signing forms
    std::cout << "\n-- Signing forms --\n";
    if (form1) alice.signForm(*form1);  // Should succeed (grade 140, sign requires 145)
    if (form2) alice.signForm(*form2);  // Should fail (sign requires 72)
    if (form3) bob.signForm(*form3);    // Should succeed (sign requires 25)

    // Try executing forms
    std::cout << "\n-- Executing forms --\n";
    if (form1) alice.executeForm(*form1);  // Should succeed (exec requires 137)
    if (form2) bob.executeForm(*form2);    // Should succeed (exec requires 45)
    if (form3) jim.executeForm(*form3);    // Should fail (exec requires 5)

    // Clean up
    delete form1;
    delete form2;
    delete form3;
    delete form4;  // nullptr check internally

    return 0;
}
