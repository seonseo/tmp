#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

namespace Global
{
	Floor	floor;
}

// void	leakCheck()
// {
// 	system("leaks a.out");
// }

int main()
{
	// atexit(leakCheck);

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());

	std::cout << std::endl;

	ICharacter* me = new Character("me");
	AMateria* tmp;

	std::cout << std::endl;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);

	std::cout << std::endl;

	ICharacter* bob = new Character("bob");

	std::cout << std::endl;

	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << std::endl;

	me->unequip(0);
	me->unequip(0);
	me->unequip(-1);
	me->unequip(1);

	std::cout << std::endl;

	me->use(0, *bob);

	std::cout << std::endl;

	me->equip(Global::floor.dequeue());
	me->equip(Global::floor.dequeue());

	std::cout << std::endl;

	delete bob;
	delete me;
	delete src;

	return 0;
}
