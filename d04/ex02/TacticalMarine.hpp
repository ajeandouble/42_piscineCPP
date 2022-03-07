# ifndef TACTICAL_MARINE_HPP
# define TACTICAL_MARINE_HPP

#include <string>
#include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine
{
	private:
		/* data */
	public:
		TacticalMarine(/* args */);
		~TacticalMarine();
		// =
		ISpaceMarine* clone() const;
		void battleCry() const;
		void rangedAttack() const;
		void meleeAttack() const;
};

# endif
