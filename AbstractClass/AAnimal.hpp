#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal {
protected:
    std::string type;

public:
    AAnimal();
    virtual ~AAnimal();

    AAnimal(const AAnimal& other);
    AAnimal& operator=(const AAnimal& other);

    virtual void makeSound() const = 0;  // funzione pura: classe astratta

    std::string getType() const;
};

#endif
