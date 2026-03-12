#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

class PhoneBook
{
private:
	Contact	contacts[8];		
	int		contactCount;
	int		oldestIndex;

	std::string	truncate(std::string str, size_t width) const;
	void		printColumn(std::string str, size_t width) const;
	void		displayContactTable() const;
	void		displayContactDetails(int index) const;

public:
	PhoneBook();
	
	void	addContact();
	void	searchContacts() const;
};

#endif
