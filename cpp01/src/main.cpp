#include "Zombie.hpp"

int main()
{
    Zombie* nz = newZombie("Ana");
    nz->announce();
    delete nz;

    randomChump("outra Ana");
    return 0;
}