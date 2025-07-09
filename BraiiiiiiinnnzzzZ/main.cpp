#include "Zombie.hpp"

int main() {
    Zombie* z = Zombie::newZombie("George");
    z->announce();
    delete z;

    Zombie::randomChump("Larry");

    return 0;
}
