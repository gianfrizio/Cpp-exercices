#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << "=== Polymorphic Animals ===" << std::endl;
    const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << dog->getType() << std::endl;
    std::cout << cat->getType() << std::endl;
    dog->makeSound();  // Dog sound
    cat->makeSound();  // Cat sound
    meta->makeSound(); // Animal generic sound

    delete meta;
    delete dog;
    delete cat;

    std::cout << "\n=== Non-Polymorphic WrongAnimals ===" << std::endl;
    const WrongAnimal* wrongAnimal = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << wrongCat->getType() << std::endl;
    wrongCat->makeSound(); // WrongAnimal sound (not overridden due to lack of virtual)

    delete wrongAnimal;
    delete wrongCat;

    return 0;
}
