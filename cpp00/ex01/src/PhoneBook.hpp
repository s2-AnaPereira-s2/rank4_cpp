#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

class PhoneBook
{
private:
	Contact	contacts[8];		// Array of 8 contacts (max capacity)
	int		contactCount;		// How many contacts we've added
	int		oldestIndex;		// Which contact to replace next (circular)

	// Private helper functions
	std::string	truncate(std::string str, size_t width) const;
	void		printColumn(std::string str, size_t width) const;
	void		displayContactTable() const;
	void		displayContactDetails(int index) const;

public:
	// Constructor
	PhoneBook();
	
	// Public interface - the main three commands
	void	addContact();
	void	searchContacts() const;
};

#endif
