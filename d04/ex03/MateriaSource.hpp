# ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
private:
	/* data */
public:
	MateriaSource(/* args */);
	~MateriaSource();
	void		learnMateria(AMateria *amateria);
	AMateria*	createMateria(std::string const & type);
};

# endif
