#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat b1("Alice", 1);
        Bureaucrat b2("Bob", 150);
        std::cout << b1 << std::endl;
        std::cout << b2 << std::endl;

        b1.incrementGrade(); // dovrebbe lanciare eccezione
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b3("Charlie", 0); // grado invalido alto
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b4("Dave", 149);
        b4.decrementGrade(); // va bene
        std::cout << b4 << std::endl;
        b4.decrementGrade(); // dovrebbe lanciare eccezione
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
