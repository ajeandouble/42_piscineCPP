# ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class	Ice : public AMateria
{
	protected:
	public:
		Ice();
		~Ice();
		Ice &operator=(Ice const &ice);

		AMateria*	clone() const;
};

# endif
