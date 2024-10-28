#include "Cat.hpp"

Cat::Cat()
	: Animal("Cat"), brain(new Brain())
{
	std::cout << "Cat default constructor called" << std::endl;
	for (int i = 0; i < 100; ++i)
	{
		std::stringstream	ss;
		ss << "Cat's idea " << (i + 1);
		brain->ideas[i] = ss.str();
	}
}

Cat::Cat(const Cat &other)
	: Animal(other), brain(new Brain())
{
	std::cout << "Cat copy constructor called" << std::endl;
	if (other.brain)
	{
		for (int i = 0; i < 100; ++i)
			brain->ideas[i] = other.brain->ideas[i];
	}
}

Cat& Cat::operator=(const Cat &other)
{
	std::cout << "Cat assignation operator called" << std::endl;
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

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete brain;
	brain = NULL;
}

Cat::Cat(const std::string& idea)
	: Animal("Cat"), brain(new Brain(idea))
{
	std::cout << "Cat constructor called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Meow! I am a cat!" << std::endl;
}

std::string	Cat::getIdea(int idx) const
{
	return (brain->ideas[idx]);
}

void	Cat::setIdea(int idx, const std::string& idea)
{
	if (brain)
		brain->ideas[idx] = idea;
}

void	Cat::printIdeas()
{
	if (brain)
	{
		for (int i = 0; i < 10; ++i)
		{
			std::cout << brain->ideas[i] << std::endl;
		}
	}
}