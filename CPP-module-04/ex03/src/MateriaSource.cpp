#include "../include/MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource() : IMateriaSource(), spellBook_() {
    // std::cout << "MateriaSource deffault constructor called\n";
}

MateriaSource::MateriaSource(const MateriaSource &src) : IMateriaSource(), spellBook_() {
    // std::cout << "MateriaSource copy constructor called\n";
    for (int i = 0; i < 4; i++)
    {
        if (src.spellBook_[i])
            spellBook_[i] = src.spellBook_[i];
    }
}

MateriaSource::~MateriaSource(){
    // std::cout << "MateriaSource deffault destructor called\n";
    for (int i = 0; i < 4; i++)
    {
        if (spellBook_[i])
            delete spellBook_[i];
    }
}

MateriaSource   &MateriaSource::operator=(const MateriaSource &src) {
    // std::cout << "MateriaSource operator = called\n";
    if (this != &src)
    {
        for (int i = 0; i < 4; i++)
        {
            if (src.spellBook_[i])
                spellBook_[i] = src.spellBook_[i];
        }
    }
    return *this;
}

int    MateriaSource::isKnownMateria(std::string const &type) {
    // std::cout << "MateriaSource isKnownMateria called\n";
    for (int i = 0; i < 4; i++)
    {
        if (spellBook_[i] && spellBook_[i]->geType() == type)
            return i;
    }
    return -1;
}

void    MateriaSource::learnMateria(AMateria *Materia) {
        // std::cout << "learnMateria (frome MateriaSource) called\n";
        if (Materia)
        {
            int i = 0;
            while (i < 4 && spellBook_[i])
                i++;
            if (i < 4 && isKnownMateria(Materia->geType()) == -1)
                spellBook_[i] = Materia;
            // else
                // std::cout << "Inventory is full\n";
        }
}

AMateria    *MateriaSource::createMateria(std::string const &type) {
    // std::cout << "MateriaSource createMateria called\n";
    if (!type.empty() && isKnownMateria(type) != -1)
        return spellBook_[isKnownMateria(type)]->clone();
    return 0;
}

