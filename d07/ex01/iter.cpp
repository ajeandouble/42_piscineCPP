#include <iostream>

template <class T>
void	iter(T *array, size_t size, void (*func)(T))
{
	for (size_t i = 0; i < size; ++i)
		func(array[i]);
}

template <class T>
void	print(T elem)
{
	std::cout << elem;
}

int	main()
{
	char	abcd[] = "abcd";
	iter(abcd, sizeof(abcd), print);
	std::cout << "\n";
}