#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>
#include <iomanip>

class HumanB
{
	private:
		std::string name;
		Weapon* weaponb;
	
	public:
		HumanB(std::string name);
		
		void attack();
		void setWeapon(Weapon& wb);
};

#endif
