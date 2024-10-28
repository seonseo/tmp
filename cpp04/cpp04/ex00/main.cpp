#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl;

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl;

	delete i;
	delete j;
	delete meta;

	std::cout << std::endl;

	const WrongAnimal* a = new WrongAnimal();
	const WrongAnimal* b = new WrongCat();
	const WrongCat*	c = new WrongCat();

	std::cout << std::endl;

	a->makeSound();
	b->makeSound();
	c->makeSound();

	std::cout << std::endl;

	delete a;
	delete b;
	delete c;

	return 0;
}