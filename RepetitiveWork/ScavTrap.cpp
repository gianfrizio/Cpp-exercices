#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap " << this->name << " constructed!" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << this->name << " destructed!" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (hitPoints <= 0) {
        std::cout << "ScavTrap " << name << " cannot attack because it's out of hit points." << std::endl;
        return;
    }
    if (energyPoints <= 0) {
        std::cout << "ScavTrap " << name << " cannot attack because it's out of energy points." << std::endl;
        return;
    }
    energyPoints--;
    std::cout << "ScavTrap " << name << " fiercely attacks " << target 
              << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode." << std::endl;
}
