#include <stdio.h>

void	upper(int t[][4], int views[4])
{
	int i;
	int line;
	int nb;
	
	i = 0;
	while (i <= 3)
	{
		if (views[i] == 4)
		{
			line = 0;
			nb = 1;
			while (line <= 3)
			{
				t[line][i] = nb;
				nb++;
				line++;
			}
		}
		if (views[i] == 1)
			t[0][i] = 4;
		i++;
	}
}

void	lower(int t[][4], int views[4])
{
	int i;
	int line;
	int nb;
	
	i = 0;
	while (i <= 3)
	{
		if (views[i] == 4)
		{
			line = 3;
			nb = 1;
			while (line >= 0)
			{
				t[line][i] = nb;
				nb++;
				line--;
			}
		}
		if (views[i] == 1)
			t[3][i] = 4;
		i++;
	}
}

void	left(int t[][4], int views[4])
{
	int i;
	int col;
	int nb;
	
	i = 0;
	while (i <= 3)
	{
		if (views[i] == 4)
		{
			col = 0;
			nb = 1;
			while (col <= 3)
			{
				t[i][col] = nb;
				nb++;
				col++;
			}
		}
		if (views[i] == 1)
			t[i][0] = 4;
		i++;
	}
}

void	rigth(int t[][4], int views[4])
{
	int i;
	int col;
	int nb;
	
	i = 0;
	while (i <= 3)
	{
		if (views[i] == 4)
		{
			col = 3;
			nb = 1;
			while (col >= 0)
			{
				t[i][col] = nb;
				nb++;
				col--;
			}
		}
		if (views[i] == 1)
			t[i][3] = 4;
		i++;
	}
}

void	fill_global(int t[][4], int views[4][4])
{
	upper(t, views[0]);
	lower(t, views[1]);
	left(t, views[2]);
	rigth(t, views[3]);
}
