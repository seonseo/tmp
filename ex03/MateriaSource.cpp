#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource default constructor called" << std::endl;
	for (int i = 0; i < 4; ++i)
        memory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < 4; ++i)
	{
		delete memory[i];
		memory[i] = other.memory[i]->clone();
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	std::cout << "MateriaSource assignation operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 4; ++i)
		{
			delete memory[i];
			memory[i] = other.memory[i]->clone();
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < 4; ++i)
	{
		if (memory[i])
		{
			delete memory[i];
			memory[i] = NULL;
		}
	}
}


void MateriaSource::learnMateria(AMateria* m)
{
	int	i;

	for (i = 0; i < 4; ++i)
	{
		if (memory[i] == NULL)
		{
			memory[i] = m;
			break ;
		}
	}
	if (i != 4)
		std::cout << "Materia " << m->getType() << " learned" << std::endl;
	else
	{
		std::cout << "MateriaSource is full" << std::endl;
		delete m;
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	int	i;

	for (i = 0; i < 4; ++i)
	{
		if (memory[i]->getType() == type)
		{
			std::cout << "Materia " << type << " created" << std::endl;
			return (memory[i]->clone());
		}
	}
	std::cout << "Materia not found" << std::endl;
	return NULL;
}
