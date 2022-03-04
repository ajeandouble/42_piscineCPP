#include <iostream>
#include <random>
#include "Zombie.hpp"
#include "ZombieEvent.hpp"

std::string zombieNames[] =
{
    "Bla",
    "yo",
    "ho"
};

Zombie  *randomChump()
{
    static  std::random_device   rd;
    std::mt19937    gen(rd());
    std::uniform_int_distribution<> distr(0, sizeof(zombieNames) / sizeof(zombieNames[0]));
    ZombieEvent zEvent;
    Zombie      *z = zEvent.newZombie(zombieNames[distr(gen)]);
    return (z);
}

int main()
{
    ZombieEvent zEvent;
    Zombie *z = zEvent.newZombie("Test");
    zEvent.setZombieType(*z, "Type");
    z->announce();
    delete z;
    Zombie *z2 = randomChump();
    z2->announce();
    delete  z2;
    Zombie *z3 = randomChump();
    z3->announce();
    delete  z3;

    return (0);
}
