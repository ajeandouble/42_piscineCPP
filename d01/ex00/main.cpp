#include <iostream>
#include "Pony.hpp"

Pony	*ponyOnTheHeap()
{
	Pony	*p_heap = new Pony;

	p_heap->setBirthDate("10/12/1991");
	p_heap->setName("Bla");
	return (p_heap);
}

Pony	ponyOnTheStack()
{
	Pony	p_stack;
	p_stack.setBirthDate("10/10/1991");
	p_stack.setName("Bla2");
	return (p_stack);
}

int main()
{
	Pony	*p_heap = ponyOnTheHeap();
	Pony	p_stack = ponyOnTheStack();
	delete	p_heap;
	return (0);
}