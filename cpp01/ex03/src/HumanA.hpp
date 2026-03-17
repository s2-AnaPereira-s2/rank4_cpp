#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include <iomanip>
#include "Weapon.hpp"

class HumanA
{
	private:		
		std::string name;
		Weapon& weapona;
	
	public:
		HumanA(std::string name, Weapon& weapona);

		void attack();
		

};

#endif
