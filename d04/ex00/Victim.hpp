# ifndef VICTIM_HPP
# define VICTIM_HPP

#include <string>

class Victim
{
	protected:
		std::string	_name;
	public:
		Victim(std::string name);
		~Victim();
		Victim &operator=(const Victim &rhs);

		std::string	getName() const;
		
		void	getPolymorphed() const;
};

std::ostream &operator<<(std::ostream &os, const Victim &v);

# endif
