#include "Weapon.hpp"

Weapon::Weapon(const std::string type) : type(type)
{}

void	Weapon::setType(const std::string str)
{
    type = str;
}

const std::string& Weapon::getType() const
{
    return type;
}

