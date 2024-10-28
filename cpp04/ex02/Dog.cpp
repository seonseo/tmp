#include "Dog.hpp"

Dog::Dog()
	: Animal("Dog"), brain(new Brain())
{
	std::cout << "Dog default constructor called" << std::endl;
	for (int i = 0; i < 100; ++i)
	{
		brain->ideas[i] = "Dog's idea " + std::to_string(i + 1);
	}
}

Dog::Dog(const Dog &other)
	: Animal(other), brain(new Brain())
{
	std::cout << "Dog copy constructor called" << std::endl;
	if (other.brain)
	{
		for (int i = 0; i < 100; ++i)
			brain->ideas[i] = other.brain->ideas[i];
	}
}

Dog& Dog::operator=(const Dog &other)
{
	std::cout << "Dog assignation operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		if (other.brain)
		{
			if (!brain)
				brain = new Brain();
			for (int i = 0; i < 100; ++i)
				brain->ideas[i] = other.brain->ideas[i];
		}
		else
		{
			delete brain;
			brain = NULL;
		}
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
	brain = NULL;
}

Dog::Dog(const std::string& idea)
	: Animal("Dog"), brain(new Brain(idea))
{
	std::cout << "Dog constructor called" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Woof! I am a dog!" << std::endl;
}

std::string	Dog::getIdea(int idx) const
{
	return (brain->ideas[idx]);
}

void	Dog::setIdea(int idx, const std::string& idea)
{
	if (brain)
		brain->ideas[idx] = idea;
}

void	Dog::printIdeas()
{
	if (brain)
	{
		for (int i = 0; i < 10; ++i)
		{
			std::cout << brain->ideas[i] << std::endl;
		}
	}
}
