#include "PhoneBook.h"
#include <iostream>
#include <iomanip>

// Default Constructor
PhoneBook::PhoneBook() 
    : contactCount(0), nextIndex(0)
{
}

// Copy Constructor
PhoneBook::PhoneBook(const PhoneBook& other) 
    : nextIndex(other.nextIndex)
{
	for (int i = 0; i < other.contactCount; i++)
		contact[i] = other.contact[i];
}

// Copy Assignment Operator
PhoneBook& PhoneBook::operator=(const PhoneBook& other) 
{
    if (this != &other) // Check for self-assignment
    {
        nextIndex = other.nextIndex;
		for (int i = 0; i < 8; i++)
			contact[i] = other.contact[i];
    }
    return *this;
}

// Destructor
PhoneBook::~PhoneBook() 
{
}

void	PhoneBook::addContact(const Contact& other)
{
	if (nextIndex < 8)
	{
		contact[nextIndex] = other;
		nextIndex++;
		if (contactCount != 8)
			contactCount++;
	}
	else
	{
		contact[0] = other;
		nextIndex = 1;
	}
}

void	PhoneBook::displayContactList() const
{
	std::cout << std::setw(10) << std::right << "Index" << "|";
	std::cout << std::setw(10) << std::right << "First Name" << "|";
	std::cout << std::setw(10) << std::right << "Last Name" << "|";
	std::cout << std::setw(10) << std::right << "Nickname" << std::endl;

	for (int i = 0; i < contactCount; i++)
	{
		std::string col1, col2, col3, col4;
	
		col1 = std::to_string(i + 1);
		col2 = contact[i].getFirstName();
		col3 = contact[i].getLastName();
		col4 = contact[i].getNickname();

		if (col1.length() > 10)
			col1 = col1.substr(0, 9) + ".";
		if (col2.length() > 10)
			col2 = col2.substr(0, 9) + ".";
		if (col3.length() > 10)
			col3 = col3.substr(0, 9) + ".";
		if (col4.length() > 10)
			col4 = col4.substr(0, 9) + ".";

		std::cout << std::setw(10) << std::right << col1 << "|";
		std::cout << std::setw(10) << std::right << col2 << "|";
		std::cout << std::setw(10) << std::right << col3 << "|";
		std::cout << std::setw(10) << std::right << col4 << std::endl;
	}
}

void	PhoneBook::displayContact(int i) const
{
	if (i < 1 || 8 < i)
		throw std::out_of_range("Invalid index: Index must be between 1 and 8.");
	if (i > contactCount)
		throw std::invalid_argument("Contact not found: No contact exists at this index.");

	const Contact& contactRef = contact[i - 1];

	std::cout << "First Name: " << contactRef.getFirstName() << std::endl;
	std::cout << "Last Name: " << contactRef.getLastName() << std::endl;
	std::cout << "Nickname: " << contactRef.getNickname() << std::endl;
	std::cout << "Phone Number: " << contactRef.getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contactRef.getDarkestSecret() << std::endl;
}
