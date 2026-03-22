#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	std::cout << "=== Testing FragTrap Construction/Destruction Chaining ===" << std::endl;
	{
		FragTrap frag("FR4G-TP");
	}
	
	std::cout << "\n=== Testing FragTrap Attributes (HP:100, Energy:100, Damage:30) ===" << std::endl;
	{
		FragTrap frag("Destroyer");
		frag.attack("Target");
		frag.takeDamage(50);
		frag.beRepaired(20);
		frag.highFivesGuys();
	}

	std::cout << "\n=== Testing FragTrap Special Ability ===" << std::endl;
	{
		FragTrap frag("HighFiver");
		frag.highFivesGuys();
	}

	std::cout << "\n=== Testing FragTrap vs ScavTrap Messages ===" << std::endl;
	{
		std::cout << "Creating ScavTrap:" << std::endl;
		ScavTrap scav("SC4V-TP");
		std::cout << "\nCreating FragTrap:" << std::endl;
		FragTrap frag("FR4G-TP");
		std::cout << "\nDestruction order (reverse):" << std::endl;
	}

	std::cout << "\n=== Testing Multiple FragTraps ===" << std::endl;
	{
		FragTrap frag1("Alpha");
		FragTrap frag2("Beta");
		FragTrap frag3("Gamma");
		
		frag1.attack("enemy1");
		frag2.attack("enemy2");
		frag3.attack("enemy3");
		
		frag1.highFivesGuys();
		frag2.highFivesGuys();
		frag3.highFivesGuys();
	}

	std::cout << "\n=== Testing Energy Depletion ===" << std::endl;
	{
		FragTrap frag("Robot");
		for (int i = 0; i < 102; i++) {
			std::cout << "Action " << i + 1 << ": ";
			frag.attack("target");
		}
	}

	std::cout << "\n=== Testing Copy Constructor ===" << std::endl;
	{
		FragTrap frag1("Original");
		FragTrap frag2(frag1);
		frag1.highFivesGuys();
		frag2.highFivesGuys();
	}

	std::cout << "\n=== Testing Copy Assignment Operator ===" << std::endl;
	{
		FragTrap frag1("First");
		FragTrap frag2("Second");
		frag2 = frag1;
		frag1.highFivesGuys();
		frag2.highFivesGuys();
	}

	return 0;
}