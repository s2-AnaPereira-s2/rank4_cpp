#include "Animal.hpp"
#include "Brain.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Creating Animals array ===" << std::endl;
    const int size = 4;
    Animal* animals[size];

    // Half Dogs, Half Cats
    for (int i = 0; i < size / 2; i++)
        animals[i] = new Dog();
    for (int i = size / 2; i < size; i++)
        animals[i] = new Cat();

    std::cout << "\n=== Animals make sounds ===" << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << animals[i]->getType() << " says: ";
        animals[i]->makeSound();
    }

    std::cout << "\n=== Deleting Animals ===" << std::endl;
    for (int i = 0; i < size; i++)
        delete animals[i];

    std::cout << "\n=== Deep copy test ===" << std::endl;
	std::cout << "\n=== copy constructor ===" << std::endl;
    Dog dog1;
    Dog dog2 = dog1; // copy constructor
	std::cout << std::endl;
	Cat cat1;
    Cat cat2 = cat1; // copy constructor
	std::cout << "\n=== copy assignment ===" << std::endl;
    Dog dog3;
    dog3 = dog1;     // copy assignment
	std::cout << std::endl;
    Cat cat3;
    cat3 = cat1;     // copy assignment
    std::cout << "\n=== End of main ===" << std::endl;
    return 0;
}