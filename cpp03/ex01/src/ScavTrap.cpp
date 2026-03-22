#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->hit = 100;
    this->energy = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap " << name << " constructed " << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) 
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other) 
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

ScavTrap::~ScavTrap() 
{
	std::cout << "ScavTrap " << name << " destroyed" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (energy <= 0 || hit <= 0) 
    {
		std::cout << "ScavTrap " << name << " can't attack!" << std::endl;
        return ;
	}
	energy -= 1;
	std::cout << "ScavTrap " << name << " attacks "  << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode!" << std::endl;
}