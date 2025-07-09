#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
private:
    std::string name; // proprio nome, diverso da ClapTrap::name

public:
    DiamondTrap(const std::string& name);
    ~DiamondTrap();

    using ScavTrap::attack;  // usa attack() di ScavTrap

    void whoAmI();
};

#endif
