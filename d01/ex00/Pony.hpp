#include <string>
#include <ctime>

class Pony
{
	private:
		tm      	birthDate;
		std::string name;
	public:
		Pony();
		~Pony();
		bool    	setBirthDate(std::string birthDate);
		bool		setName(std::string name);
		tm		  	getBirthDate();
		std::string	getName();
};
