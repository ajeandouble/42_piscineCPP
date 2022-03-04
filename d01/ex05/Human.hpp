# ifndef HUMAN_HPP
# define HUMAN_HPP

#include "Brain.hpp"

class Human
{
	public:
		Human(/* args */);
		~Human();
		std::string identify();
		Brain &getBrain();
	private:
		Brain   b;
};

# endif
