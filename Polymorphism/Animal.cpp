#include "Animal.hpp"

Animal::Animal() : type("Animal") {
    std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal& other) {
    *this = other;
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other)
        type = other.type;
    std::cout << "Animal assignment operator called" << std::endl;
    return *this;
}

void Animal::makeSound() const {
    std::cout << "Animal makes an undefined sound" << std::endl;
}

std::string Animal::getType() const {
    return type;
}
