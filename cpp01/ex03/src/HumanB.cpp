#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weaponb(NULL)
{}

void HumanB::setWeapon(Weapon& wb)
{
    this->weaponb = &wb;
}


void HumanB::attack()
{
    if (!weaponb)
    {
        std::cout << name << " attacks with no weapon " << std::endl;
        return ;
    }
    else
    {
        std::cout << name << " attacks with their " << weaponb->getType() << std::endl;
        return ;
    }
}
