#include "ClapTrap.hpp"

int main() {
    ClapTrap ct("Gianfrizio");

    ct.attack("an enemy");
    ct.takeDamage(3);
    ct.beRepaired(5);

    // Provare ad attaccare fino a finire energia
    for (int i = 0; i < 11; ++i) {
        ct.attack("another enemy");
    }

    ct.takeDamage(15);
    ct.beRepaired(10);

    return 0;
}
