#include "Zombie.hpp"

void    Zombie::announce()
{
    std::cout << '<' << this->name << " (" << this->type << ")> > Braiiiiiiinnnssss..." << std::endl;
}
