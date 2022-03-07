# ifndef SORCERER_HPP
# define SORCERER_HPP

#include <string>
#include <ostream>
#include "Victim.hpp"
#include "Peon.hpp"

class Sorcerer
{
	protected:
		std::string _name;
		std::string _title;
	public:
		Sorcerer(std::string name, std::string title);
		Sorcerer(const Sorcerer &);
		Sorcerer& operator=(const Sorcerer &rhs);
		~Sorcerer();

		std::string	getName() const;
		std::string	getTitle() const;

		void	polymorph(Victim const &v);
		void	polymorph(Peon const &v);
};

std::ostream &operator<<(std::ostream &os, const Sorcerer &s);

# endif
