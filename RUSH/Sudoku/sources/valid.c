#include "functions.h"
#include <stdio.h>

int posValid(int (*grid)[9], int pos)
{
	int i;
	int x;
	int y;
	
	if (pos == 81)
		return (1);

	x = pos / 9;
	y = pos % 9;

	// Si déja remplie, on passe à la suivante 
	if (grid[x][y] != 0)
		return posValid(grid, pos + 1);

	// Debug : display_grid(grid);

	i = 1;
	while (i <= 9)
	{
		if (absentLine(grid, x, i) && absentColumn(grid, y, i) && absentBlock(grid, x, y, i)) 			
		{
		
			grid[x][y] = i;
			if (posValid(grid, pos + 1))
			{
				// Debug : printf("\nPos : %d et grid x y : %d\n", pos, grid[x][y]); 
				return (1);
			}
		}
		i++;
	}	
	/* On arrive la si tous les chiffres de 1 à 9 ont été testés pour la case en question,
	   et si aucun n'est valide
	
	   Cette seule ligne permet de ré ass	
	 */
	grid[x][y] = 0; 
	// Debug : printf("\n L50 Pos : %d et nbr = %d\n", pos, grid[x][y]);
	return (0);
}

int absentLine(int (*grid)[9], int line, int nbr) 
{
	int i;
	
	i = 0;
	while (grid[line][i])
	{
		/* Si 0, alors le nombre est déja présent sur la ligne FALSE */
		if (grid[line][i] == nbr)
			return (0);	
		i++;
	}
	return (1); /* Si 1, alors absent sur la ligne TRUE*/
}

int absentColumn(int (*grid)[9], int column, int nbr) 
{
	int i;
	
	i = 0;
	while (grid[i][column])
	{
		if (grid[i][column] == nbr)
			return (0);
		i++;
	}
	return (1);
}
#include <stdio.h>
int absentBlock(int (*grid)[9], int line, int column, int nbr) 
{
	int _i;
	int _j;
		
 	
	_i = line - (line % 3);
	_j = column - (column % 3);	
	line = _i;
	
	while (line < _i + 3)
	{
		column = _j;
		while (column < _j + 3)
		{
			if (grid[line][column] == nbr)
				return (0);
			column++;
		}
		line++;
	}
	return (1);
}
