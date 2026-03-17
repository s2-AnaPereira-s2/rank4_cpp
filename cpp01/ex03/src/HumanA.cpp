#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapona) :  name(name), weapona(weapona)
{}

void HumanA::attack()
{
    std::cout << name << " attacks with their " << weapona.getType() << std::endl;
}