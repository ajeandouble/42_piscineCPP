# ifndef SQUAD_HPP
# define SQUAD_HPP

#include <string>
#include "ISquad.hpp"
#include "TacticalMarine.hpp"

typedef struct s_squadList
{
	ISpaceMarine	*marine;
	s_squadList		*next;
	s_squadList(ISpaceMarine * const marine);
	s_squadList(ISpaceMarine * const marine, struct s_squadList * const next);
	~s_squadList();
}				t_squadList;

class Squad : public ISquad
{
	private:
		t_squadList		*_squadList_vector;
		std::string		_name;
		unsigned int	_count;
	public:
		Squad();
		~Squad();
		Squad& operator= (Squad const & obj);

		int getCount() const;
		ISpaceMarine* getUnit(int n) const;

		int	push(ISpaceMarine* const spaceMarine);
		std::string getName() const;
};

# endif
