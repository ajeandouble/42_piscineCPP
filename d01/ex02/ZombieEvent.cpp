#include "ZombieEvent.hpp"

void    ZombieEvent::setZombieType(Zombie &z, std::string type)
{
    z.type = type;
}

Zombie  *ZombieEvent::newZombie(std::string name)
{
    Zombie  *z = new Zombie();
    z->name = name;
    return (z);
}
