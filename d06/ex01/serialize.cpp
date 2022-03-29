#include <iostream>
#include <time.h>
#include <random>
#include <limits>

#define ALPHA_LEN	8

char	alphanum[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

typedef struct {
	char	alpha1[ALPHA_LEN + 1];
	int		number;
	char	alpha2[ALPHA_LEN + 1];
} Data;

void	*serialize(void)
{
	char	*bytes = new char[(ALPHA_LEN + 1) * 2 + sizeof(int)];

	for (size_t i = 0; i < ALPHA_LEN; ++i)
	{
		bytes[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
		std::cout << bytes[i];
	}
	bytes[ALPHA_LEN] = '\0';
	std::cout << ", ";
	for (size_t i = 8; i < ALPHA_LEN + 8; ++i)
	{
		bytes[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
		std::cout << bytes[i	];
	}
	bytes[ALPHA_LEN + 8] = '\0';
	int	number = std::rand() % INT_MAX;
	std::cout << ", " << number << std::endl;
	*static_cast<int *>(static_cast<void *>(&bytes[16])) = number;
	return (static_cast<void *>(bytes));
}

Data	*deserialize(void *raw)
{
	Data *d = new Data;
	for (size_t i = 0; i < 8; ++i)
	{
		d->alpha1[i] = static_cast<char *>(raw)[i];
		d->alpha2[i] = static_cast<char *>(raw)[i + 8];
	}
	d->number = *static_cast<int *>(static_cast<void *>(static_cast<char *>(raw) + 16));
	return (d);
}
int	main()
{
	std::srand(time(0));
	void	*bytes = serialize();
	Data *d = deserialize(bytes);
	std::cout << d->alpha1 << ", " << d->alpha2 << ", " << d->number << std::endl;
	return (0);
}
