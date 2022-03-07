# ifndef ASSAULT_TERMINATOR_HPP
# define ASSAULT_TERMINATOR_HPP

#include <string>
#include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine
{
	private:
		/* data */
	public:
		AssaultTerminator(/* args */);
		~AssaultTerminator();
		// =
		ISpaceMarine* clone() const;
		void battleCry() const;
		void rangedAttack() const;
		void meleeAttack() const;
};

# endif
