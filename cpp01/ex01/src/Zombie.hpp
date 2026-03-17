#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
    private:
        std::string name;

    public:
	    Zombie();
        ~Zombie();

        void announce() const;
        void setName(std::string str);
	    
};

Zombie* zombieHorde( int N, std::string name );
void randomChump( std::string name );

#endif