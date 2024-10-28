#include "AMateria.hpp"

AMateria::AMateria()
	: type("materia")
{
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(AMateria const& other)
	: type(other.type)
{
	std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria&	AMateria::operator=(AMateria const& other)
{
	std::cout << "AMateria assignation operator called" << std::endl;
	if (this != &other)
	{
		if (type != other.type)
			std::cout << "AMateria type is different" << std::endl;
	}
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;
}


AMateria::AMateria(std::string const& type)
	: type(type)
{
	std::cout << "AMateria type constructor called" << std::endl;
}


const std::string&	AMateria::getType() const
{
	return (type);
}

void	AMateria::use(ICharacter& target)
{
	(void)target;
}