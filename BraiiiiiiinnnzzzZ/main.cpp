// main.cpp
#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main() {
    std::cout << "Creating zombie on heap:\n";
    Zombie* heapZombie = newZombie("HeapZombie");
    heapZombie->announce();
    delete heapZombie; // important!

    std::cout << "\nCreating zombie on stack:\n";
    randomChump("StackZombie");

    return 0;
}

