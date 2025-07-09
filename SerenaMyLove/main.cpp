#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

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

    std::cout << "\n=== Construction/Destruction chaining test ===" << std::endl;
    {
        ScavTrap temp("Temporary");
    } // distruzione temp

    return 0;
}
