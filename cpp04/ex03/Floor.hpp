#ifndef FLOOR_HPP
#define FLOOR_HPP

#include "Cure.hpp"
#include "Ice.hpp"

struct MateriaQueue
{
	AMateria* item;
	MateriaQueue* next;
};

class Floor
{
public:
	Floor();
	Floor(const Floor& other);
	Floor& operator=(const Floor& other);
	~Floor();

	void enqueue(AMateria* item);
	AMateria* dequeue(void);
private:
	void	clear();
	void	copyFrom(const Floor& other);

	MateriaQueue*	head;
};
namespace Global
{
	extern Floor floor;
}

#endif
