#include <iostream>
#include "../include/ICharacter.hpp"

ICharacter::ICharacter()
{
    // std::cout << "ICharacter deffault constructor called\n";
}

ICharacter::ICharacter(const ICharacter &src)
{
    // std::cout << "ICharacter copy constructor called\n";
    *this = src;
}

ICharacter  &ICharacter::operator=(const ICharacter &src)
{
    // std::cout << "ICharacter operator = called\n";
    (void)src;
    return (*this);
}
