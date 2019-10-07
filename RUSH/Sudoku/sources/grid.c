#include "functions.h"
#include <stdlib.h>

int (*fill_grid(char **argv))[9]
{
	int i;
	int j;
	static int grid[9][9];
	int (*ptr_grid)[9];
	
	i = 1;
	while (i < 10)
	{
		j = 0;
		while (j < 9)
		{
			if (argv[i][j] == '.')
				grid[i - 1][j] = 0;
			else
				grid[i - 1][j] = argv[i][j] - '0';
			j++;
		}
		i++;
	}	
	
	ptr_grid = grid;
	return (ptr_grid);

}

void display_grid(int (*grid)[9])
{
	int i;
	int j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (grid[i][j] == 0)
				ft_putchar('.');
			else
				ft_putnbr(grid[i][j]);
			j++;
		} 
		write(1, "\n", 1);
		i++;
	}
}
