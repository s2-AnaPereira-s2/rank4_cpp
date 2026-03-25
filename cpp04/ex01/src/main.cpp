#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int	main() {
	std::cout << "=== Test 1: Basic polymorphic deletion ===" << std::endl;
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;
		delete i;
	}

	std::cout << "\n=== Test 2: Array of Animals (half Dog, half Cat) ===" << std::endl;
	{
		const int size = 6;
		Animal* animals[size];
		
		// Fill array: half Dogs, half Cats
		for (int i = 0; i < size / 2; i++)
			animals[i] = new Dog();
		for (int i = size / 2; i < size; i++)
			animals[i] = new Cat();
		
		// Delete all as Animals
		std::cout << "\nDeleting all animals:" << std::endl;
		for (int i = 0; i < size; i++)
			delete animals[i];
	}

	std::cout << "\n=== Test 3: Deep copy with copy constructor ===" << std::endl;
	{
		Dog original;
		std::cout << "\nCreating copy using copy constructor:" << std::endl;
		Dog copy(original);
		std::cout << "\nBoth dogs exist independently" << std::endl;
	}

	std::cout << "\n=== Test 4: Deep copy with assignment operator ===" << std::endl;
	{
		Cat cat1;
		Cat cat2;
		std::cout << "\nAssigning cat1 to cat2:" << std::endl;
		cat2 = cat1;
		std::cout << "\nBoth cats exist independently" << std::endl;
	}

	std::cout << "\n=== Test 5: Self-assignment ===" << std::endl;
	{
		Dog dog;
		Dog& ref = dog;
		std::cout << "\nSelf-assigning via reference:" << std::endl;
		dog = ref;
		std::cout << "No crash - self-assignment handled correctly" << std::endl;
	}

	std::cout << "\n=== Test 6: Copy survives original deletion ===" << std::endl;
	{
		Dog* original = new Dog();
		Dog copy(*original);
		std::cout << "\nDeleting original:" << std::endl;
		delete original;
		std::cout << "Copy still valid:" << std::endl;
		copy.makeSound();
	}

	return 0;
}