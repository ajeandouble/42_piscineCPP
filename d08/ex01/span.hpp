# ifndef SPAN_HPP
# define SPAN_HPP

#include <stdexcept>

class Span
{
	private:
		unsigned int _size;
		int			*_array;
		unsigned int _max_size;
	public:
		Span	(unsigned int N);
		void	addNumber(int number);
		int		shortestSpan();
		int		longestSpan();
		int 	&operator[](int index);
};

# endif