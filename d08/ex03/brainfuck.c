#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

# define CELL_ARRAY_SIZE	10240

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("Usage: %s \"your program\"", av[1]);
		return (0);
	}

	char	cells[CELL_ARRAY_SIZE] = {0};
	size_t	d_p = 0;
	char	input;

	for (size_t i_p = 0; i_p < strlen(av[1]); ++i_p)
	{
		switch (av[1][i_p])
		{
			case '>':
				++d_p;
				break ;
			case '<':
				--d_p;
				break ;
			case '+':
				cells[d_p]++;
				break ;
			case '-':
				cells[d_p]--;
				break ;
			case '.':
				putchar(cells[d_p]);
				break ;
			case ',':
				cells[d_p] = getc(stdin);
				break ;
			case '[':
				if (cells[d_p] == 0)
				{
					unsigned int loop_count = 1;
					while (loop_count!= 0)
					{
						++i_p;
						if (av[1][i_p] == ']')
							--loop_count;
						else if (av[1][i_p] == '[')
							++loop_count;
					}
				}
				break ;
			case ']':
				if (cells[d_p] != 0)
				{
					unsigned int loop_count = 1;
					while (loop_count)
					{
						--i_p;
						if (av[1][i_p] == '[')
							--loop_count;
						else if (av[1][i_p] == ']')
							++loop_count;
					}
				}
				break;
		}
		// printf("ip=%d cells[%d]=%d '%c'\n", i_p, d_p, cells[d_p], av[1][i_p]);
	}
}