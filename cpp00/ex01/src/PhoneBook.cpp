#include "PhoneBook.hpp"

// Constructor - initialize with no contacts
PhoneBook::PhoneBook()
{
	this->contactCount = 0;
	this->oldestIndex = 0;
}

// Truncate string to width, adding '.' if too long
std::string	PhoneBook::truncate(std::string str, size_t width) const
{
	if (str.length() > width)
		return str.substr(0, width - 1) + ".";
	return str;
}

// Print a column with fixed width, right-aligned
void	PhoneBook::printColumn(std::string str, size_t width) const
{
	std::cout << std::setw(width) << truncate(str, width);
}

// Display full details of one contact
void	PhoneBook::displayContactDetails(int index) const
{
	std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
	std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
}

// Display table of all contacts
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

// ADD command - prompt for all fields and add a contact
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

	// Store the contact (replace oldest if full)
	contacts[oldestIndex] = newContact;
	oldestIndex = (oldestIndex + 1) % 8;  // Circular: 0,1,2...7,0,1,2...
	
	if (contactCount < 8)
		contactCount++;
	
	std::cout << "Contact added successfully!" << std::endl;
}

// SEARCH command - display table then show details for selected index
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

	// Simple validation - check if input is a single digit
	if (input.length() != 1 || !isdigit(input[0]))
	{
		std::cout << "Invalid index!" << std::endl;
		return;
	}

	int index = input[0] - '0';  // Convert char to int
	
	if (index < 0 || index >= contactCount)
	{
		std::cout << "Index out of range!" << std::endl;
		return;
	}

	std::cout << std::endl;
	displayContactDetails(index);
}
