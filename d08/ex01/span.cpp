#include <limits.h>
#include <math.h>
#include "span.hpp"

#define MAX(A, B)((A) > (B) ? (A) : (B))
#define MIN(A, B)((A) < (B) ? (A) : (B))
#define ABS(A, B)((A) < (B) ? (A) : (B))

Span::Span(unsigned int N)
{
	_array = new int[N];
	_size = 0;
	_max_size = N;
}

void	Span::addNumber(int number)
{
	if (_size >= _max_size)
		throw std::out_of_range("Too many numbers already");
	_array[_size++] = number;
}

int &Span::operator[](int index)
{
	if (index < 0 || index > static_cast<int>(_size))
		throw std::out_of_range("Index out of range");
	return (_array[index]);
}

	#include <iostream>

int	Span::shortestSpan()
{
	if (_size == 0)
		throw	std::out_of_range("No numbers left");
	int	sht_span = INT_MAX;

	for (size_t i = 0; i < _size; ++i)
	{
		for (size_t j = 0; j < _size; ++j)
		{
			if (i != j && abs(_array[i] - _array[j]) < sht_span)
				sht_span = abs(_array[i] - _array[j]);
		}
	}
	return (sht_span);
}

int	Span::longestSpan()
{
	if (_size == 0)
		throw	std::out_of_range("No numbers left");
	int	lg_span = INT_MIN;

	for (size_t i = 0; i < _size; ++i)
	{
		for (size_t j = 0; j < _size; ++j)
		{
			if (i != j && abs(_array[i] - _array[j]) > lg_span)
				lg_span = abs(_array[i] - _array[j]);
		}
	}
	return (lg_span);
}
