#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : name(name), hit(10), energy(10), attackDamage(0) 
{
    std::cout << "Constructor has been called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor has been called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    energy -= 1;
    std::cout << name << " attacks " << target << ", causing" << hit << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    attackDamage += amount;
    hit -= attackDamage;
    std::cout << name << " was attacked, causing" << amount << " of attack damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    energy -= 1;
    hit += amount;
    std::cout << name << " was repaired, by" << amount << std::endl;
}

