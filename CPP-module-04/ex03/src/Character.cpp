#include "../include/Character.hpp"
#include <iostream>

Character::Character() : ICharacter(), name_("DEFAULT_NAME"), slots_() {
    // std::cout << "Character deffault constructor called\n";
}

Character::Character(const Character &src) : ICharacter(src), name_(src.getName()), slots_() {
    // std::cout << "Character copy constructor called\n";
    for (int i = 0; i < 4; i++)
    {
        if (src.slots_[i])
            slots_[i] = src.slots_[i];
    }
}

Character::Character(const std::string &name) : ICharacter(), name_(name), slots_() {
    // std::cout << "Character name constructor called\n";
}

Character::~Character() {
    // std::cout << "Character deffault destructor called\n";
    for (int i = 0; i < 4; i++)
    {
        if (slots_[i])
            delete slots_[i];
    }
}

Character &Character::operator=(const Character &src) {
    // std::cout << "Character operator = called\n";
    if (this != &src)
    {
        name_ = src.name_;
        for (int i = 0; i < 4; i++)
        {
            if (src.slots_[i])
                slots_[i] = src.slots_[i];
        }
    }
    return *this;
}

const std::string &Character::getName() const {
    // std::cout << "Character getName called\n";
    return (name_);
}

void    Character::equipe(AMateria *m) {
    // std::cout << "Character equipe called\n";
    if (m)
    {
        int i = 0;
        while (i < 4 && slots_[i])
            i++;
        if (i < 4)
            slots_[i] = m;
        // else
        //     std::cout << "Inventory is full\n";
    }
}

void    Character::unequip(int idx) {
    // std::cout << "Character unequipe called\n";
    if (idx < 4 && idx > -1)
    {
        if (slots_[idx])
            slots_[idx] = NULL;
    }
}

void    Character::use(int idx, ICharacter &target) {
    // std::cout << "Character use called\n";
    if (idx < 4 && idx > -1 && slots_[idx])
        slots_[idx]->use(target);
}
