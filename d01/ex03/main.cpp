#include <iostream>
#include <random>
#include "Zombie.hpp"
#include "ZombieEvent.hpp"
#include "ZombieHorde.hpp"

int main()
{
    ZombieHorde *zHorde = new ZombieHorde(5);
    delete      zHorde;
    return (0);
}
