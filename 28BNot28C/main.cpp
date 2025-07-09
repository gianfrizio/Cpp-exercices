#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat bob("Bob", 1);            // Top grade
        Bureaucrat jim("Jim", 150);          // Lowest grade
        Bureaucrat alice("Alice", 70);       // Intermediate grade
        Bureaucrat eve("Eve", 30);           // Medium-high grade

        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robot("Bender");
        PresidentialPardonForm pardon("Marvin");

        // Signing forms
        std::cout << "\n-- Signing forms --\n";
        jim.signForm(shrub);    // Should fail (grade too low)
        alice.signForm(shrub);  // Should succeed
        alice.signForm(robot);  // Should fail
        bob.signForm(robot);    // Should succeed
        bob.signForm(pardon);   // Should succeed

        // Executing forms
        std::cout << "\n-- Executing forms --\n";
        jim.executeForm(shrub);   // Should fail (grade too low)
        alice.executeForm(shrub); // Should succeed, create file
        alice.executeForm(robot); // Should fail (exec grade too low)
        bob.executeForm(robot);   // Should succeed (50% chance success/failure)
        bob.executeForm(pardon);  // Should succeed, pardon message

        // Try to execute unsigned form
        ShrubberyCreationForm unSignedForm("garden");
        bob.executeForm(unSignedForm);  // Should fail (not signed)

        // Increment and decrement grades to test exceptions
        std::cout << "\n-- Grade increment/decrement test --\n";
        Bureaucrat test("Test", 2);
        std::cout << test << std::endl;
        test.incrementGrade();  // goes to 1 (highest)
        std::cout << test << std::endl;
        try {
            test.incrementGrade(); // exception
        } catch (std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
        test.decrementGrade();  // back to 2
        std::cout << test << std::endl;
        test.decrementGrade();  // to 3
        std::cout << test << std::endl;
        try {
            for (int i = 0; i < 150; ++i)
                test.decrementGrade(); // eventually exception
        } catch (std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

    } catch (std::exception & e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
