#include "Zombie.hpp"

Zombie::Zombie()
{
	this->name = "";
}

void Zombie::setName(std::string str)
{
    this->name = str;
}

Zombie::~Zombie()
{
    std::cout << this->name << " is destroyed" << std::endl;
}

void Zombie::announce() const
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
