#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl;

	delete j; //should not create a leak
	delete i;

	std::cout << std::endl << "---animal array test---" << std::endl << std::endl;

	int				idx;
	const Animal	*animals[4];

	for (idx = 0; idx < 2; ++idx)
		animals[idx] = new Dog();
	for (idx = 2; idx < 4; ++idx)
		animals[idx] = new Cat();
	
	std::cout << std::endl;
	
	for(idx = 0; idx < 4; ++idx)
		animals[idx]->makeSound();

	std::cout << std::endl;

	//print ideas
	for (idx = 0; idx < 2; ++idx)
	{
		((Dog**)animals)[idx]->printIdeas();
	}

	std::cout << std::endl;

	for (idx = 2; idx < 4; ++idx)
	{
		((Cat**)animals)[idx]->printIdeas();
	}

	std::cout << std::endl;

	for (idx = 0; idx < 4; ++idx)
	{
		delete animals[idx];
		animals[idx] = NULL;
	}

	std::cout << std::endl << "---deep copy test---" << std::endl << std::endl;

	Cat	*cat1;
	Cat	*cat2;
	Cat	*cat3;

	cat1 = new Cat("Hunting mice");
	cat2 = new Cat(*cat1);
	cat3 = new Cat("sleeping on the floor");

	std::cout << std::endl;

	cat1->printIdeas();
	delete cat1;
	cat2->printIdeas();

	std::cout << std::endl;

	*cat2 = *cat3;
	delete cat3;
	cat2->printIdeas();

	std::cout << std::endl;

	delete cat2;
	return 0;
}
	