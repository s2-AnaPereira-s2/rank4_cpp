#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main()
{
	PhoneBook	phoneBook;
	std::string	action;

	std::cout << std::endl << "*********************************************" << std::endl;
    std::cout << "*      WELCOME TO MY AWESOME PHONEBOOK      *" << std::endl;
    std::cout << "*********************************************" << std::endl;

	while (true)
	{
        std::cout << "\nYou can: ADD, SEARCH or EXIT" << std::endl;
		std::cout << "\nWhat would you like: ";
		std::getline(std::cin, action);
		std::cout << std::endl;
		if (std::cin.eof()) 
		{
			std::cout << std::endl << "I have to go now...Tchau!" << std::endl;
			return 0;
		}

		if (action == "ADD")
			phoneBook.addContact();
		else if (action == "SEARCH")
			phoneBook.searchContacts();
		else if (action == "EXIT")
		{
			std::cout << "See ya..byeee" << std::endl;
			break;
		}
		else
			std::cout << "Hey hey hey..that's invalid!" << std::endl;
		if (std::cin.eof()) 
		{
			std::cout << std::endl << "I have to go now...Tchau!" << std::endl;
			return 0;
		}
	}
	return 0;
}
