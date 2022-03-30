#include <iostream>

template <class T>
void	swap(T *a, T *b)
{
	T tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

template <class T>
T	max(T a, T b)
{
	return (a > b ? a : b);
}

template <class T>
T	min(T a, T b)
{
	return (a < b ? a : b);
}

int	main()
{
	int a = 42, b = 45;
	swap(&a, &b);
	std::cout << a << ", " << b << std::endl;
	std::cout << max(a, b) << std::endl << min(a, b) << std::endl;
	return (0);
}