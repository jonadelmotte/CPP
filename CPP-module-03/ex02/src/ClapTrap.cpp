#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap() : _name(""), _Hit_points(10), _Energy_points(10), _Attack_damage(0)
{
    std::cout << "On the seventh day God created nobody" << "\n";   
}

ClapTrap::ClapTrap(const ClapTrap &ClapTrap) : _name(ClapTrap.get_name()), _Hit_points(ClapTrap.get_hp()), _Energy_points(ClapTrap.get_ep()), _Attack_damage(ClapTrap.get_ad())
{
    std::cout << "On the seventh day God created " << _name << "\n";
}

ClapTrap::ClapTrap(const std::string &name) : _name(name), _Hit_points(10), _Energy_points(10), _Attack_damage(0)
{
    std::cout << "On the seventh day God created " << _name << "\n";
}

ClapTrap::~ClapTrap()
{
    std::cout << _name << " are dead.... let us mourn in peace\n";
}

ClapTrap    &ClapTrap::operator=(const ClapTrap &ClapTrap)
{
    if (this != &ClapTrap)
    {
        set_name(ClapTrap.get_name());
        set_hp(ClapTrap.get_hp());
        set_ep(ClapTrap.get_ep());
        set_ad(ClapTrap.get_ad());
    }
    return *this;
}

void    ClapTrap::attack(const std::string &target)
{
    if (_Hit_points > 0 && _Attack_damage > 0 && _Energy_points > 0 && !target.empty())
    {
        std::cout << _name << " attacks " << target << ", causing " << _Attack_damage << " points of damage !\n";
        _Energy_points--;
    }
    else if (_Hit_points <= 0)
        std::cout << _name << " couldn't attack, they seem to be dead\n";
    else if (target.empty())
        std::cout << _name << " couldn't attack they sadly dosen't have a target\n";
    else if (_Energy_points <= 0)
        std::cout << _name << " couldn't attack, they are way to tired\n";
    else
        std::cout << _name << " couldn't attack, they are way to weak\n";
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (amount > 0 && _Hit_points > 0)
    {
        if (amount > _Hit_points)
            amount = _Hit_points;
        _Hit_points -= amount;
        std::cout << _name << " took " << amount << " damage points !\n";
    }
    else if (_Hit_points <= 0)
        std::cout << _name << " are already dead\n";
    else
        std::cout << _name << " did not take any damage\n";
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (amount > 0 && _Hit_points > 0 && _Energy_points > 0)
    {
        if (_Hit_points < MAX_HEALTH)
        {
            long total = amount + _Hit_points;
            if (total >= MAX_HEALTH)
                amount -= total - MAX_HEALTH;
            _Hit_points += amount;
            std::cout << _name << " added " << amount << " health points to their health !\n";
            _Energy_points--;
        }
        else
            std::cout << _name << " couldn't repaire they are already way to healthy !\n";
    }
    else if (_Hit_points <= 0)
        std::cout << _name << " couldn't repaire they seem to be dead !\n";
    else if (_Energy_points <= 0)
        std::cout << _name << " couldn't repaire they are way to tired !\n";
    else
        std::cout << _name << " did not add any health points to their health\n";
}

void    ClapTrap::set_name(const std::string &name)
{
    _name = name;
}

void    ClapTrap::set_hp(const unsigned int &hp)
{
    _Hit_points = hp;
}

void    ClapTrap::set_ep(const unsigned int &ep)
{
    _Energy_points = ep;
}

void    ClapTrap::set_ad(const unsigned int &ad)
{
    _Attack_damage = ad;
}

std::string ClapTrap::get_name() const
{
    return _name;
}

unsigned int ClapTrap::get_hp() const
{
    return _Hit_points;
}

unsigned int ClapTrap::get_ep() const
{
    return _Energy_points;
}

unsigned int ClapTrap::get_ad() const
{
    return _Attack_damage;
}


// void    ClapTrap::add_attack_damage(unsigned int amount)
// {
//     _Attack_damage += amount;
// }

// void ClapTrap::rm_or_add_energy(int amount)
// {
//     _Energy_points += amount;
// }
