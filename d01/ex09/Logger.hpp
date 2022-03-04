# ifndef LOGGER_HPP
# define LOGGER_HPP

#include <fstream>

class Logger
{
	private:
		std::string	makeLogEntry(std::string const &message);
		std::ofstream file;
	public:
		Logger(std::string filename);
		~Logger();
		void	log(std::string const &dest, std::string const &message);
		void	logToConsole(std::string const &message);
		void	logToFile(std::string const &message);
};

# endif
