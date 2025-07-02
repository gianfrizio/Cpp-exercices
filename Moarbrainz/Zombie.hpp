#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
private:
    std::string _name;

public:
    Zombie();
    ~Zombie();

    void announce() const;
    void setName(std::string name);
};

#endif
