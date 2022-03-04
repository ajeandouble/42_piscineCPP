#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>

void	usage(std::string programName)
{
	std::cout << programName << " filename string1 string2" << std::endl;
}

int	main(int ac, char **av)
{
    if (ac != 4)
    {
		usage(av[0]);
		exit(EXIT_FAILURE);
    }
	std::ifstream f(av[1]);
	std::string line;
	std::string a = av[2];
	std::string b = av[3];
	if (!f.is_open())
	{
		std::cerr << "Unable to open the file" << std::endl;
		exit(EXIT_FAILURE);
	}
	bool found = false;
	while (getline(f, line))
	{
		std::cout << "line=" << line << std::endl;
		size_t index = line.find(a);
		if (index != std::string::npos)
			found = true;
	}
	if (!found)
	{
		std::cout << "Nothing can be replaced" << std::endl;
		exit(EXIT_FAILURE);
	}
	f.clear();
	f.seekg(0);
	std::ofstream foutput(std::string(av[1]) + ".replace");
	if (!foutput.is_open())
	{
		std::cerr << "Unable to write to file" << std::endl;
		exit(EXIT_FAILURE);
	}
	std::stringstream ss_buf;
	ss_buf << f.rdbuf();
	std::string buf = ss_buf.str();
	size_t index;
	while ((index = buf.find(a)) != std::string::npos)
		buf.replace(index, b.length(), b);
	foutput << buf;
	f.close();
	foutput.close();

	return (EXIT_SUCCESS);
}
