#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
public:
	Dog();
	Dog(const Dog &other);
	Dog& operator=(const Dog &other);
	virtual ~Dog();

	Dog(const std::string& idea);

	virtual void	makeSound() const;
	std::string		getIdea(int idx) const;
	void			setIdea(int idx, const std::string& idea);
	void			printIdeas();
private:
	Brain*	brain;
};

#endif