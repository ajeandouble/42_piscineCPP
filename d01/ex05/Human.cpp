#include <iostream>
#include "Human.hpp"
#include "Brain.hpp"

Human::Human()
{
}

Human::~Human()
{
}

std::string Human::identify()
{
    return (this->b.identify());
}

Brain   &Human::getBrain()
{
    return (b);
}