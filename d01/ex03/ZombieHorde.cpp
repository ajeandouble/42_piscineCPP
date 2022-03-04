#include <random>
#include "ZombieHorde.hpp"

std::string zombieNames[] =
{
	"Bla",
	"yo",
	"ho"
};

std::string	ZombieHorde::randomChump()
{
	static  std::random_device   rd;
	static  std::mt19937    gen(rd());
	static  std::uniform_int_distribution<> distr(0, (sizeof(zombieNames) / sizeof(zombieNames[0]) - 1));
	return (zombieNames[distr(gen)]);
}

ZombieHorde::ZombieHorde(unsigned int N)
{
	this->zArray = new Zombie[N];
	for (size_t i = 0; i < N; i++)
	{
		this->zArray[i].name = this->randomChump();
		zArray[i].announce();
	}
}

ZombieHorde::~ZombieHorde()
{
	delete[]	this->zArray;
}
