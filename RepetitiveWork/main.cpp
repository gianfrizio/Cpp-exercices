#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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

    std::cout << "\n=== Construction/Destruction chaining test ===" << std::endl;
    {
        ScavTrap tempScav("TemporaryScav");
        FragTrap tempFrag("TemporaryFrag");
    } // distruzione tempScav e tempFrag in ordine inverso

    return 0;
}
