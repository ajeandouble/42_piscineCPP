#include <iostream>
#include "Logger.hpp"

int	main()
{
	Logger	l("log_file.txt");
	l.log("console", "Yo");
	l.log("file", "Yo");
	return (0);
}
