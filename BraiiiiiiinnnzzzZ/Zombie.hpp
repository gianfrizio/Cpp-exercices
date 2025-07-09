#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
private:
    std::string _name;

public:
    Zombie(std::string name);
    ~Zombie();

    void announce() const;

    // Static methods now part of the class
    static Zombie* newZombie(std::string name);
    static void randomChump(std::string name);
};

#endif
