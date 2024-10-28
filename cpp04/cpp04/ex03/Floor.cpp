#include "Floor.hpp"

Floor::Floor() :head(NULL) {}

Floor::Floor(const Floor& other) : head(NULL)
{
	copyFrom(other);
}

Floor& Floor::operator=(const Floor& other)
{
	if (this != &other)
	{
        clear();
        copyFrom(other);
    }
    return *this;
}

Floor::~Floor()
{
	 clear();
}


void	Floor::enqueue(AMateria* item)
{
	MateriaQueue* new_tail = new MateriaQueue;

	new_tail->item = item;
	new_tail->next = NULL;
	if (!head)
		head = new_tail;
	else
	{
		MateriaQueue*	curr = head;
		while (curr->next)
			curr = curr->next;
		curr->next = new_tail;
	}
}

AMateria*	Floor::dequeue(void)
{
	if (!head)
		return NULL;

	MateriaQueue*	curr = head;
	MateriaQueue*	prev = NULL;

	while (curr->next)
	{
		prev = curr;
		curr = curr->next;
	}

	if (prev)
		prev->next = NULL;
	else
		head = NULL;

	AMateria*	item = curr->item;
	delete curr;
	return item;
}

void	Floor::clear()
{
	MateriaQueue*	temp;

	while (head)
	{
		temp = head;
		head = head->next;
		delete temp->item;
		delete temp;
	}
}

void	Floor::copyFrom(const Floor& other)
{
	if (!other.head)
        return;

	head = new MateriaQueue;
	head->item = other.head->item->clone();
	head->next = NULL;

	MateriaQueue*	curr = head;
	MateriaQueue*	otherCurr = other.head->next;

	while (otherCurr)
	{
		curr->next = new MateriaQueue;
		curr = curr->next;
		curr->item = otherCurr->item->clone();
		otherCurr = otherCurr->next;
	}
	curr->next = NULL;
}
