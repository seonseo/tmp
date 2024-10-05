#include "my_awesome_phonebook.h"

int	main()
{
	PhoneBook	phoneBook;
	Contact		contact;
	std::string input;

	while(!std::cin.eof())
	{
		std::cout << "Please enter a command: ADD, SEARCH or EXIT" << std::endl;
		std::getline(std::cin, input);
		if (input == "ADD")
		{
			if (!getInput("Enter First Name: ", input)) break;
			contact.setFirstName(input);
			if (!getInput("Enter Last Name: ", input)) break;
			contact.setLastName(input);
			if (!getInput("Enter Nickname: ", input)) break;
			contact.setNickname(input);
			if (!getInput("Enter Phone Number: ", input)) break;
			contact.setPhoneNumber(input);
			if (!getInput("Enter Darkest Secret: ", input)) break;
			contact.setDarkestSecret(input);

			phoneBook.addContact(contact);
		}
		else if (input == "SEARCH")
		{
			phoneBook.displayContactList();
			std::cout << "Enter the index of the contact you want to see: ";
			if (!std::getline(std::cin, input)) break;
			try
			{
				int	index = std::stoi(input);
				phoneBook.displayContact(index);
			}
			catch (const std::invalid_argument& e)
			{
				std::cerr << e.what() << std::endl;
			}
			catch (const std::out_of_range& e)
			{
				std::cerr << e.what() << std::endl;
			}
		}
		else if (input == "EXIT")
			break;
	}
	std::cout << "Exit the program." << std::endl;
	return 0;
}

bool	getInput(const std::string& prompt, std::string& input)
{
	input = "";

	while (input == "")
	{
		std::cout << prompt;
		if (!std::getline(std::cin, input))
		{
			std::cout << std::endl;
			return false;  // EOF or input error
		}
		if (input == "")
			std::cerr << "Please enter a valid input." << std::endl;
	}
	return true;
}
