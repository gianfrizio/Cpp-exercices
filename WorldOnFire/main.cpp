#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
    std::cout << "=== Basic Leak Check ===" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;
    delete i;

    std::cout << "\n=== Array of Animals ===" << std::endl;
    const int SIZE = 4;
    Animal* animals[SIZE];

    for (int i = 0; i < SIZE / 2; ++i)
        animals[i] = new Dog();
    for (int i = SIZE / 2; i < SIZE; ++i)
        animals[i] = new Cat();

    for (int i = 0; i < SIZE; ++i)
        animals[i]->makeSound();

    for (int i = 0; i < SIZE; ++i)
        delete animals[i];

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
