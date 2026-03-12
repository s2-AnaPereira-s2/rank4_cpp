#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main()
{
	PhoneBook	phoneBook;
	std::string	action;

	std::cout << "Welcome to My Awesome PhoneBook!" << std::endl;

	while (true)
	{
        std::cout << "You can: ADD, SEARCH or EXIT" << std::endl;
		std::cout << "\nWhat would you like: ";
		std::getline(std::cin, action);

		if (action == "ADD")
			phoneBook.addContact();
		else if (action == "SEARCH")
			phoneBook.searchContacts();
		else if (action == "EXIT")
		{
			std::cout << "Goodbye!" << std::endl;
			break;
		}
		else
			std::cout << "Invalid action!" << std::endl;
	}
	return 0;
}
