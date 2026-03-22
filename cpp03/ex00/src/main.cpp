#include "ClapTrap.hpp"

int main()
{
    std::cout << "=== Test 1: Basic Creation ===" << std::endl;
    ClapTrap ana("Ana");

    std::cout << "\n=== Test 2: Basic Actions ===" << std::endl;
    ana.attack("YKW");
    ana.takeDamage(3);
    ana.beRepaired(5);

    std::cout << "\n=== Test 3: Energy Depletion, try attack ===" << std::endl;
    ClapTrap keillin("Kei");
    for (int i = 0; i < 12; i++) 
    {
        keillin.attack("YKW");
    }

    std::cout << "\n=== Test 4: Energy Depletion, try repair ===" << std::endl;
    ClapTrap taninha("Taninha");
    taninha.takeDamage(15);
    taninha.attack("YKW");
    taninha.beRepaired(5);

    std::cout << "\n=== Test 5: Copy Constructor ===" << std::endl;
    ClapTrap thobias("Thobi");
    ClapTrap thobi_copy(thobias);

    std::cout << "\n=== Test 6: Copy Assignment ===" << std::endl;
    ClapTrap gabriel("Gabi");
    ClapTrap samir("Sami");
    samir = gabriel;

    std::cout << "\n=== Destructors ===" << std::endl;
    return 0;
}