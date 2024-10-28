#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <string>
#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
protected:
	std::string	type;
public:
	AMateria();
	AMateria(const AMateria& other);
	AMateria&	operator=(const AMateria& other);
	virtual	~AMateria();

	AMateria(std::string const& type);

	const std::string&	getType() const; //Returns the materia type
	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter& target);
};

#endif