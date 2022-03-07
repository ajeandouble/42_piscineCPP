# ifndef PEON_HPP
# define PEON_HPP

#include <string>
#include "Victim.hpp"

class Peon : public Victim
{
	private:
		std::string	_name;
	public:
		Peon(std::string name);
		~Peon();
		Peon &operator=(const Peon &rhs);

		std::string	getName() const;

		void	getPolymorphed() const;
};

std::ostream &operator<<(std::ostream &os, const Peon &p);

# endif
