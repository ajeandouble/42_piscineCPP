#include <iostream>
#include "Squad.hpp"

s_squadList::s_squadList(ISpaceMarine * const marine)
{
	this->marine = marine;
	this->next = nullptr;
}

s_squadList::s_squadList(ISpaceMarine * const marine, t_squadList * const next)
{
	this->marine = marine;
	this->next = next;
}


Squad::Squad()
{
	this->_count = 0;
}

Squad::~Squad()
{
	t_squadList	*elem;
	if ((elem = this->_squadList_vector))
	{
		while (elem)
		{
			t_squadList *next = elem->next;
			free(elem);
			elem = next;
		}

	}
}

int	Squad::push(ISpaceMarine* const spaceMarine)
{
	if (!this->_squadList_vector)
		this->_squadList_vector = new t_squadList(spaceMarine);
	else
	{
		t_squadList *elem = this->_squadList_vector;
		while (elem->next)
			elem = elem->next;
		elem->next = new t_squadList(spaceMarine);
	}
	++this->_count;
	return (this->_count);
}

int Squad::getCount() const
{
	return (this->_count);
}

ISpaceMarine* Squad::getUnit(int n) const
{
	std::cout << n << std::flush;
	if (n < this->_count)
	{
		t_squadList	*elem = this->_squadList_vector;
		while (n--)
			if (elem->next)
				elem = elem->next;
		std::cout << n;
		return (elem->marine);
	}
	std::cout << n << std::flush;
	return (nullptr);
}

std::string Squad::getName() const
{
	return (this->_name);
}
