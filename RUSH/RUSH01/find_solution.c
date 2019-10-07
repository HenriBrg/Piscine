#include <unistd.h>

void print_table(int a[4][4]);
int ft_check_up(int t[4][4], int views[4][4], int i, int j);
int ft_check_down(int t[4][4], int views[4][4], int i, int j);
int ft_check_left(int t[4][4], int views[4][4], int i, int j);
int ft_check_right(int t[4][4], int views[4][4], int i, int j);

int check_col_line(int t[4][4], int i, int j)
{
	int x;
	int y;

	x = 0;
	while (x <= 3)
	{
		if (t[i][j] != 0 && t[i][j] == t[i][x])
		{
			return (0);
		}
		x++;
	}
	y = 0;
	while (y <= 3)
	{
		if (t[i][j] != 0 && t[i][j] == t[y][j])
		{
			return (0);
		}
		y++;
	}
	return (1);
}

int isValid(int t[4][4], int views[4][4], int i, int j)
{
	printf("i = %d\tj = %d\n", i, j);
	if (!(check_col_line(t, i, j)))
		return (0 * printf("check_col_line\n"));
	if (ft_check_up(t, views, i, j)
			&& ft_check_down(t, views, i, j)
			&& ft_check_left(t, views, i, j)
			&& ft_check_right(t, views, i, j))
		return (printf("check up down ok\n") + 15);
	else
		return (0 * printf("checkupdown\n"));
	printf("check_ok\n");
	return (1);
}

int solve(int t[][4], int views[4][4], int pos)
{
	int i;
	int j;
	int k;
	int check;

	check = 0;
	if (pos == 16)
		return (1);
	i = pos / 4;
	j = pos % 4;
	if (t[i][j] != 0)
		check = solve(t, views, pos + 1);
	k = 1;
	while (!check && k <= 4)
	{
		t[i][j] = k;
		if ( pos == 16 && isValid(t, views,  i, j))
		{
			check = solve(t, views, pos + 1);
		}
		else
		{
			print_table(t);
			t[i][j] = 0;
			printf("\n" );
		}
		k++;
	}
	return (check);
}
