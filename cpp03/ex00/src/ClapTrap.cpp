#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : name(name), hit(10), energy(10), attackDamage(0) 
{
    std::cout << "Constructor has been called for "<< name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : name(other.name), hit(other.hit), energy(other.energy), attackDamage(other.attackDamage)
{
    //*this = other;
    std::cout << "Copy constructor has been called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other)
    {
        this->name = other.name;
        this->hit = other.hit;
        this->energy = other.energy;
        this->attackDamage = other.attackDamage;
    }
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor has been called for " << name << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (hit <= 0 || energy <= 0)
    {
        std::cout << name << " can't attack!" << std::endl;
        return;
    }
    energy -= 1;
    std::cout << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    hit -= amount;
    if(hit < 0)
        hit = 0;
    std::cout << name << " was attacked, taking " << amount << " points of damage!!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hit <= 0 || energy <= 0)
    {
        std::cout << name << " can't be repaired!" << std::endl;
        return;
    }
    energy -= 1;
    hit += amount;
    std::cout << name << " was repaired, by " << amount << " points" << std::endl;
}

