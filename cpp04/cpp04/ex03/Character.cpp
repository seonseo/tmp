#include "Character.hpp"

Character::Character()
	: name("noName")
{
	std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < 4; ++i)
        slots[i] = NULL;
}

Character::Character(Character const& other)
	: name(other.name)
{
	std::cout << "Character copy constructor called" << std::endl;
	for (int i = 0; i < 4; ++i)
	{
		delete slots[i];
		slots[i] = other.slots[i]->clone();
	}
}

Character& Character::operator=(Character const& other)
{
	std::cout << "Character assignment operator called" << std::endl;
	if (this != &other)
	{
		name = other.name;
		for (int i = 0; i < 4; ++i)
		{
			delete slots[i];
			slots[i] = other.slots[i]->clone();
		}
	}
	return (*this);
}

Character::~Character()
{
	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; ++i)
	{
		if (slots[i])
		{
			delete slots[i];
			slots[i] = NULL;
		}
	}
}

Character::Character(const std::string name)
	: name(name)
{
	std::cout << "Character name constructor called" << std::endl;
	for (int i = 0; i < 4; ++i)
        slots[i] = NULL;
}

std::string const & Character::getName() const
{
	return (name);
}

void Character::equip(AMateria* m)
{
	int	i;

	for (i = 0; i < 4; ++i)
	{
		if (slots[i] == NULL)
		{
			slots[i] = m;
			break ;
		}
	}
	if (i != 4)
		std::cout << getName() << " equiped " << m->getType() << " materia" << std::endl;
	else
	{
		std::cout << "slots are full" << std::endl;
		delete m;
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || 3 < idx)
	{
		std::cout << "invalid index" << std::endl;
		return ;
	}
	if (slots[idx] == NULL)
	{
		std::cout << "slot is empty" << std::endl;
		return ;
	}
	std::cout << getName() << " unequiped " << slots[idx]->getType() << " materia" << std::endl;
	Global::floor.enqueue(slots[idx]);
	slots[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || 3 < idx)
	{
		std::cout << "invalid index" << std::endl;
		return ;
	}
	if (slots[idx] == NULL)
	{
		std::cout << "slot is empty" << std::endl;
		return ;
	}
	slots[idx]->use(target);
}
