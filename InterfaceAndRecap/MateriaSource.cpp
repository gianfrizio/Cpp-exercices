#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; ++i)
        sources[i] = nullptr;
    std::cout << "MateriaSource constructed" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
    for (int i = 0; i < 4; ++i)
        sources[i] = nullptr;
    for (int i = 0; i < 4; ++i) {
        if (other.sources[i])
            sources[i] = other.sources[i]->clone();
    }
    std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    if (this != &other) {
        clearSources();
        for (int i = 0; i < 4; ++i) {
            if (other.sources[i])
                sources[i] = other.sources[i]->clone();
            else
                sources[i] = nullptr;
        }
    }
    std::cout << "MateriaSource assignment operator called" << std::endl;
    return *this;
}

MateriaSource::~MateriaSource() {
    clearSources();
    std::cout << "MateriaSource destructed" << std::endl;
}

void MateriaSource::clearSources() {
    for (int i = 0; i < 4; ++i) {
        if (sources[i]) {
            delete sources[i];
            sources[i] = nullptr;
        }
    }
}

void MateriaSource::learnMateria(AMateria* m) {
    if (!m)
        return;
    for (int i = 0; i < 4; ++i) {
        if (!sources[i]) {
            sources[i] = m;
            std::cout << "MateriaSource learned " << m->getType() << std::endl;
            return;
        }
    }
    // full, do nothing
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; ++i) {
        if (sources[i] && sources[i]->getType() == type)
            return sources[i]->clone();
    }
    return nullptr;
}
