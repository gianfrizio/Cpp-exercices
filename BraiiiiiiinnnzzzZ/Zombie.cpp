#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name) : _name(name) {}

Zombie::~Zombie() {
    std::cout << _name << " has been destroyed" << std::endl;
}

void Zombie::announce() const {
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

// Moved from global functions to static class methods
Zombie* Zombie::newZombie(std::string name) {
    return new Zombie(name);
}

void Zombie::randomChump(std::string name) {
    Zombie z(name);
    z.announce();
}
