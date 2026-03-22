#include "ScavTrap.hpp"

int main()
{
    std::cout << "=== Test 1: Construction/Destruction Chaining ===" << std::endl;
	{
		ScavTrap scav1("Guardian");
	}
	
	std::cout << "\n=== Test 2: ScavTrap Basic Actions ===" << std::endl;
	ScavTrap scav2("Warrior");
	scav2.attack("Enemy1");
	scav2.takeDamage(30);
	scav2.beRepaired(20);
	scav2.guardGate();
	
	std::cout << "\n=== Test 3: ScavTrap Stats (100 HP, 50 Energy, 20 Damage) ===" << std::endl;
	ScavTrap scav3("Ninja");
	scav3.attack("Enemy2");
	scav3.takeDamage(150);  
	scav3.attack("Enemy3");  
	scav3.beRepaired(50);    
	
	std::cout << "\n=== Test 4: Energy Depletion ===" << std::endl;
	ScavTrap scav4("Robot");
	for (int i = 0; i < 51; i++) 
	{
		std::cout << "Action " << i + 1 << ": ";
		scav4.attack("Target");
	}
	
	std::cout << "\n=== Test 5: Copy Constructor ===" << std::endl;
	ScavTrap scav5("Original");
	scav5.attack("Enemy");
	ScavTrap scav6(scav5);
	scav6.guardGate();
	
	std::cout << "\n=== Test 6: Copy Assignment Operator ===" << std::endl;
	ScavTrap scav7("First");
	ScavTrap scav8("Second");
	scav8 = scav7;
	scav8.attack("Enemy");
	
	std::cout << "\n=== Test 7: ClapTrap vs ScavTrap ===" << std::endl;
	ClapTrap clap("Clappy");
	ScavTrap scav9("Scavvy");
	
	std::cout << "\nClapTrap attack:" << std::endl;
	clap.attack("Target");
	
	std::cout << "\nScavTrap attack:" << std::endl;
	scav9.attack("Target");
	
	scav9.guardGate();
	
	std::cout << "\n=== Destructors (in reverse order of creation) ===" << std::endl;
	return 0;
}