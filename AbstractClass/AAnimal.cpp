#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal") {
    std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::~AAnimal() {
    std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) {
    *this = other;
    std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
    if (this != &other)
        type = other.type;
    std::cout << "AAnimal assignment operator called" << std::endl;
    return *this;
}

std::string AAnimal::getType() const {
    return type;
}
