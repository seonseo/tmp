#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.h"

class PhoneBook
{
public:
	// Default constructor
	PhoneBook();
	// Copy constructor
	PhoneBook(const PhoneBook& other);
	// Assignment operator
	PhoneBook& operator=(const PhoneBook& other);
    // Destructor
    ~PhoneBook();

	void	addContact(const Contact& other);
	void	displayContactList() const;
	void	displayContact(int i) const;

private:
	Contact contact[8];
	int		contactCount;
	int		nextIndex;
};

#endif
