#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
    std::cout << "=== Basic Leak Check ===" << std::endl;
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();
    delete j;
    delete i;

    std::cout << "\n=== Array of Animals ===" << std::endl;
    const int SIZE = 4;
    AAnimal* animals[SIZE];

    for (int idx = 0; idx < SIZE / 2; ++idx)
        animals[idx] = new Dog();
    for (int idx = SIZE / 2; idx < SIZE; ++idx)
        animals[idx] = new Cat();

    for (int idx = 0; idx < SIZE; ++idx)
        animals[idx]->makeSound();

    for (int idx = 0; idx < SIZE; ++idx)
        delete animals[idx];

    std::cout << "\n=== Deep Copy Test ===" << std::endl;
    Dog original;
    Dog copy = original;
    original = Dog();

    std::cout << "\n=== Wrong Animal Test ===" << std::endl;
    const WrongAnimal* wa = new WrongAnimal();
    const WrongAnimal* wc = new WrongCat();
    wa->makeSound();  // Generic
    wc->makeSound();  // Still generic, not overridden
    delete wa;
    delete wc;

    return 0;
}
