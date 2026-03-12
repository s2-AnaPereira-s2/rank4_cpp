#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->contactCount = 0;
	this->oldestIndex = 0;
}


std::string	PhoneBook::truncate(std::string str, size_t width) const
{
	if (str.length() > width)
		return str.substr(0, width - 1) + ".";
	return str;
}

void	PhoneBook::printColumn(std::string str, size_t width) const
{
	std::cout << std::setw(width) << truncate(str, width);
}

void	PhoneBook::displayContactDetails(int index) const
{
	std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
	std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
}

void	PhoneBook::displayContactTable() const
{
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;

	for (int i = 0; i < contactCount && i < 8; i++)
	{
		std::cout << std::setw(10) << i << "|";
		printColumn(contacts[i].getFirstName(), 10);
		std::cout << "|";
		printColumn(contacts[i].getLastName(), 10);
		std::cout << "|";
		printColumn(contacts[i].getNickname(), 10);
		std::cout << std::endl;
	}
}

void	PhoneBook::addContact()
{
	Contact		newContact;
	std::string	input;

	std::cout << "Enter first name: ";
	std::getline(std::cin, input);
	newContact.setFirstName(input);

	std::cout << "Enter last name: ";
	std::getline(std::cin, input);
	newContact.setLastName(input);

	std::cout << "Enter nickname: ";
	std::getline(std::cin, input);
	newContact.setNickname(input);

	std::cout << "Enter phone number: ";
	std::getline(std::cin, input);
	newContact.setPhoneNumber(input);

	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, input);
	newContact.setDarkestSecret(input);

	contacts[oldestIndex] = newContact;
	oldestIndex = (oldestIndex + 1) % 8;
	
	if (contactCount < 8)
		contactCount++;
	
	std::cout << "Contact added successfully!" << std::endl;
}

void	PhoneBook::searchContacts() const
{
	if (contactCount == 0)
	{
		std::cout << "PhoneBook is empty!" << std::endl;
		return;
	}

	displayContactTable();

	std::cout << "Enter index to view: ";
	std::string input;
	std::getline(std::cin, input);

	if (input.length() != 1 || !isdigit(input[0]))
	{
		std::cout << "Invalid index!" << std::endl;
		return;
	}

	int index = input[0] - '0'; 
	
	if (index < 0 || index >= contactCount)
	{
		std::cout << "Index out of range!" << std::endl;
		return;
	}

	std::cout << std::endl;
	displayContactDetails(index);
}
