#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
public:
	Animal();
	Animal(const Animal &other);
	Animal& operator=(const Animal &other);
	virtual ~Animal();

	virtual void	makeSound() const;
	std::string		getType() const;
protected:
	Animal(const std::string& type);
	std::string type;
};

#endif