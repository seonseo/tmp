#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal
{
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &other);
	WrongAnimal& operator=(const WrongAnimal &other);
	~WrongAnimal();

	void		makeSound() const;
	std::string	getType() const;
protected:
	WrongAnimal(const std::string& type);
	std::string type;
};

#endif