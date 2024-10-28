#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <string>
#include "ICharacter.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Floor.hpp"

class Character : public ICharacter
{
public:
	Character();
	Character(Character const& other);
	Character& operator=(Character const& other);
	virtual ~Character();

	Character(const std::string name);

	virtual std::string const & getName() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);

private:
	AMateria*	slots[4];
	std::string	name;
};

#endif
