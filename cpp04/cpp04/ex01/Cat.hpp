#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
public:
	Cat();
	Cat(const Cat &other);
	Cat& operator=(const Cat &other);
	virtual ~Cat();

	Cat(const std::string& idea);

	virtual void	makeSound() const;
	std::string		getIdea(int idx) const;
	void			setIdea(int idx, const std::string& idea);
	void			printIdeas();
private:
	Brain*	brain;
};

#endif