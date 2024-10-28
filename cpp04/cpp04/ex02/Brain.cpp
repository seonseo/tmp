#include "Brain.hpp"

Brain::Brain()
{
}

Brain::Brain(const Brain &other)
{
	for(int i = 0; i < 100; ++i)
		ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain &other)
{
	if (this != &other)
		return *this;
	for(int i = 0; i < 100; ++i)
		ideas[i] = other.ideas[i];
	return *this;
}

Brain::~Brain()
{
}

Brain::Brain(const std::string& idea)
{
	for (int i = 0; i < 100; ++i)
    {
        ideas[i] = idea;
    }
}