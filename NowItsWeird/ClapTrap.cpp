#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name)
    : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap " << name << " constructed!" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << name << " destructed!" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (hitPoints <= 0) {
        std::cout << "ClapTrap " << name << " cannot attack because it's out of hit points." << std::endl;
        return;
    }
    if (energyPoints <= 0) {
        std::cout << "ClapTrap " << name << " cannot attack because it's out of energy points." << std::endl;
        return;
    }
    energyPoints--;
    std::cout << "ClapTrap " << name << " attacks " << target 
              << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (hitPoints <= 0) {
        std::cout << "ClapTrap " << name << " is already dead." << std::endl;
        return;
    }
    hitPoints -= amount;
    if (hitPoints < 0) hitPoints = 0;
    std::cout << "ClapTrap " << name << " takes " << amount << " points of damage! "
              << "Remaining hit points: " << hitPoints << std::endl;
    if (hitPoints == 0) {
        std::cout << "ClapTrap " << name << " has died!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (hitPoints <= 0) {
        std::cout << "ClapTrap " << name << " cannot be repaired because it's dead." << std::endl;
        return;
    }
    if (energyPoints <= 0) {
        std::cout << "ClapTrap " << name << " cannot be repaired because it's out of energy points." << std::endl;
        return;
    }
    energyPoints--;
    hitPoints += amount;
    std::cout << "ClapTrap " << name << " is repaired by " << amount << " points! "
              << "Current hit points: " << hitPoints << std::endl;
}

const std::string& ClapTrap::getName() const { return name; }
int ClapTrap::getHitPoints() const { return hitPoints; }
int ClapTrap::getEnergyPoints() const { return energyPoints; }
int ClapTrap::getAttackDamage() const { return attackDamage; }
