#include <iostream>

int main(int ac, char **av)
{
	if (ac > 1)
	{
		std::string sentence = "";
		for (int i = 1; i < ac; ++i)
		   for (char *c = av[i]; *c; c++)
				std::cout << (char)toupper(*c);
		std::cout << std::endl;
	}
	else
		std::cout << "SHHHHH... I THINK THE STUDENTS ARE ASLEEP..." << std::endl;
	return (0);
}
