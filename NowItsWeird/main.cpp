#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
    std::cout << "=== ClapTrap test ===" << std::endl;
    ClapTrap ct("Gianfrizio");
    ct.attack("an enemy");
    ct.takeDamage(3);
    ct.beRepaired(5);

    std::cout << "\n=== ScavTrap test ===" << std::endl;
    ScavTrap st("Scavy");
    st.attack("a bad guy");
    st.takeDamage(10);
    st.beRepaired(20);
    st.guardGate();

    std::cout << "\n=== FragTrap test ===" << std::endl;
    FragTrap ft("Fraggy");
    ft.attack("a tough opponent");
    ft.takeDamage(15);
    ft.beRepaired(10);
    ft.highFivesGuys();

    std::cout << "\n=== DiamondTrap test ===" << std::endl;
    DiamondTrap dt("Diamond");
    dt.attack("a diamond enemy");  // usa attack di ScavTrap
    dt.takeDamage(25);
    dt.beRepaired(30);
    dt.guardGate();    // da ScavTrap
    dt.highFivesGuys(); // da FragTrap
    dt.whoAmI();

    std::cout << "\n=== Construction/Destruction chaining test ===" << std::endl;
    {
        ScavTrap tempScav("TemporaryScav");
        FragTrap tempFrag("TemporaryFrag");
        DiamondTrap tempDiamond("TemporaryDiamond");
    }

    return 0;
}
