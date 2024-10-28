#include "Animal.hpp"

Animal::Animal()
	: type("animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &other)
	: type(other.type)
{
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal&	Animal::operator=(const Animal &other)
{
	std::cout << "Animal assignation operator called" << std::endl;
	if (this == &other)
		return *this;
	type = other.type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const std::string& type)
	: type(type)
{
	std::cout << "Animal constructor called" << std::endl;
}

void	Animal::makeSound() const
{
    std::cout << "Roar! I am an animal!" << std::endl;
}

std::string	Animal::getType() const
{
	return type;
}
