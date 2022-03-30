# ifndef EASY_FIND_HPP
# define EASY_FIND_HPP

template <typename T>
int	easyfind(T &arr, int value)
{
	typename T::iterator it = std::find(arr.begin(), arr.end(), value);
	if (it == arr.end())
			throw	std::exception();
	return (*it);
}

# endif