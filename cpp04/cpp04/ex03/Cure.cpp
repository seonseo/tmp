#include "Cure.hpp"

Cure::Cure()
	: AMateria("cure")
{
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(Cure const& other)
	: AMateria(other.type)
{
	std::cout << "Cure copy constructor called" << std::endl;
}

Cure&	Cure::operator=(Cure const& other)
{
	std::cout << "Cure assignation operator called" << std::endl;
	if (this != &other)
		AMateria::operator=(other);
	return (*this);
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
}

AMateria*	Cure::clone() const
{
	std::cout << "Cure clone called" << std::endl;
	return (new Cure());
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
