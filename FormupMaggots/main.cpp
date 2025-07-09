#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    std::cout << "=== Test valid signing ===" << std::endl;
    try {
        Bureaucrat bob("Bob", 42);
        Form taxForm("Tax Form", 30, 50);

        std::cout << bob << std::endl;
        std::cout << taxForm << std::endl;

        bob.signForm(taxForm);  // Non può firmare (grade too low)
        Bureaucrat alice("Alice", 10);
        alice.signForm(taxForm); // Firma con successo

        std::cout << taxForm << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test grade too high exception for Form ===" << std::endl;
    try {
        Form invalidFormHigh("Invalid High", 0, 10);
    } catch (std::exception& e) {
        std::cerr << "Caught exception creating form: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test grade too low exception for Form ===" << std::endl;
    try {
        Form invalidFormLow("Invalid Low", 10, 151);
    } catch (std::exception& e) {
        std::cerr << "Caught exception creating form: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test increment/decrement exceptions for Bureaucrat ===" << std::endl;
    try {
        Bureaucrat highRank("HighRank", 1);
        std::cout << highRank << std::endl;
        highRank.incrementGrade(); // Deve lanciare eccezione
    } catch (std::exception& e) {
        std::cerr << "Caught exception incrementing grade: " << e.what() << std::endl;
    }

    try {
        Bureaucrat lowRank("LowRank", 150);
        std::cout << lowRank << std::endl;
        lowRank.decrementGrade(); // Deve lanciare eccezione
    } catch (std::exception& e) {
        std::cerr << "Caught exception decrementing grade: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test signing form already signed ===" << std::endl;
    try {
        Bureaucrat signer("Signer", 20);
        Form form2("Form2", 20, 30);
        signer.signForm(form2);  // Firma con successo
        signer.signForm(form2);  // Firma già fatto, non cambia nulla ma stampa il messaggio
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
