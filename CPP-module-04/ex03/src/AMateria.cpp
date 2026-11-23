#include "../include/AMateria.hpp"
#include <iostream>

AMateria::AMateria() : type_("")
{
    // std::cout << "AMateria deffault constructor called\n";
}

AMateria::AMateria(const AMateria &src) : type_(src.geType())
{
    // std::cout << "AMateria copy constructor called\n";
}

AMateria::AMateria(std::string const &type) : type_(type)
{
    // std::cout << "AMateria name constructor called\n";
}

AMateria::~AMateria()
{
    // std::cout << "AMateria deffault destructor called\n";
}

AMateria    &AMateria::operator=(const AMateria &other)
{
    // std::cout << "AMateria operator = called\n";
    if (this != &other)
    {
        seType(other.geType());
    }
    return (*this);
}

std::string const   &AMateria::geType() const
{
    // std::cout << "AMateria geType called\n";
    return (this->type_);
}

void    AMateria::seType(const std::string &src)
{
    // std::cout << "AMateria seType called\n";
    type_ = src;
}

void   AMateria::use(ICharacter &target)
{
    // std::cout << "AMateria use called\n";
    (void)target;
}
