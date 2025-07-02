#include "Zombie.hpp"
#include <iostream>

// Dichiarazione esterna
Zombie* zombieHorde(int N, std::string name);

int main() {
    int hordeSize = 5;
    Zombie* horde = zombieHorde(hordeSize, "Zed");

    for (int i = 0; i < hordeSize; ++i) {
        horde[i].announce();
    }

    delete[] horde;
    return 0;
}
