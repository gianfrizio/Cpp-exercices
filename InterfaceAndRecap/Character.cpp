#include "Character.hpp"
#include <iostream>

Character::Character(std::string const & name) : name(name) {
    for (int i = 0; i < 4; ++i)
        inventory[i] = nullptr;
    std::cout << "Character " << name << " constructed" << std::endl;
}

Character::Character(const Character& other) : name(other.name) {
    for (int i = 0; i < 4; ++i)
        inventory[i] = nullptr;
    for (int i = 0; i < 4; ++i) {
        if (other.inventory[i])
            inventory[i] = other.inventory[i]->clone();
    }
    std::cout << "Character copy constructor called" << std::endl;
}

Character& Character::operator=(const Character& other) {
    if (this != &other) {
        name = other.name;
        clearInventory();
        for (int i = 0; i < 4; ++i) {
            if (other.inventory[i])
                inventory[i] = other.inventory[i]->clone();
            else
                inventory[i] = nullptr;
        }
    }
    std::cout << "Character assignment operator called" << std::endl;
    return *this;
}

Character::~Character() {
    clearInventory();
    std::cout << "Character " << name << " destructed" << std::endl;
}

std::string const & Character::getName() const {
    return name;
}

void Character::clearInventory() {
    for (int i = 0; i < 4; ++i) {
        if (inventory[i]) {
            delete inventory[i];
            inventory[i] = nullptr;
        }
    }
}


void Character::equip(AMateria* m) {
    if (!m)
        return;
    for (int i = 0; i < 4; ++i) {
        if (!inventory[i]) {
            inventory[i] = m;
            std::cout << "Character " << name << " equips " << m->getType() << std::endl;
            return;
        }
    }
    // inventory full, do nothing
}

void Character::unequip(int idx) {
    if (idx < 0 || idx >= 4)
        return;
    if (inventory[idx]) {
        std::cout << "Character " << name << " unequips " << inventory[idx]->getType() << " from slot " << idx << std::endl;
        inventory[idx] = nullptr;
    }
}

void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx >= 4)
        return;
    if (inventory[idx]) {
        inventory[idx]->use(target);
    }
}
