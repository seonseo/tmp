#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class Brain
{
public:
	Brain();
	Brain(const Brain &other);
	Brain& operator=(const Brain &other);
	~Brain();

	Brain(const std::string& idea);
	
	std::string	ideas[100];
};

#endif
