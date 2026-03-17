#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name)
{}

void HumanB::setWeapon(Weapon& wb)
{
    this->weaponb = &wb;
}


void HumanB::attack()
{
    std::cout << name << " attacks with their " <<  weaponb->getType() << std::endl;
}