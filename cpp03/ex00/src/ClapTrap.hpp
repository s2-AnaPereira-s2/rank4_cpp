#include <iostream>
#include <string>

class ClapTrap
{
    private:
        std::string name;
        int hit;
        int energy;
        int attackDamage;

    public:
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap& other);
        ClapTrap& operator=(const ClapTrap& other);
        ~ClapTrap();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

