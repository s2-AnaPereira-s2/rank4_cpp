#include "Zombie.hpp"

Zombie::Zombie(std:: string str)
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
