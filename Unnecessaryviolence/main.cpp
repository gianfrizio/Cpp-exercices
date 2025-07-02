#include "HumanA.hpp"
#include "HumanB.hpp"

int main() {
    Weapon club("crude spiked club");

    HumanA bob("Bob", club);
    bob.attack();

    club.setType("some other type of club");
    bob.attack();

    Weapon axe("battle axe");
    HumanB jim("Jim");
    jim.attack(); // no weapon
    jim.setWeapon(axe);
    jim.attack();
    axe.setType("heavy iron axe");
    jim.attack();

    return 0;
}
