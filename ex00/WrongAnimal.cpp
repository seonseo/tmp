#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
	: type("WrongAnimal")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
	: type(other.type)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << "WrongAnimal assignation operator called" << std::endl;
	if (this == &other)
		return *this;
	type = other.type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& type)
	: type(type)
{
	std::cout << "WrongAnimal constructor called" << std::endl;
}

void	WrongAnimal::makeSound() const
{
    std::cout << "Roar! I am an WrongAnimal!" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return type;
}
