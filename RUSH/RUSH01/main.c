#include <unistd.h>
#include <stdio.h>

void solve(int t[][4], int views[4][4], int pos);
void fill_global(int t[4][4], int views[4][4]);

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void print_table(int a[4][4])
{
	int i;
	int j;

	i = 0;
	(void)a;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ft_putchar(' ');
			ft_putchar(a[i][j] + '0');
			ft_putchar(' ');
			j++;
		}
		i++;
		write(1, "\n", 1);
	}
}

void fill_array(int a[][4], char *av)
{
	int i;
	int j;
	
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			a[i][j] = 0;
			j++;
		}
		i++;
	}
}

int		ft_valid(char *av, int params[][4])
{
	int i;
	int j;
	int k;
	char a[16];

	i = 0;
	j = 0;
	while (av[i] != '\0')
	{
		if (av[i] == ' ' || av[i] == '\t')
			i++;
		else if (!(av[i] == '1' || av[i] == '2' || av[i] == '3' || av[i] == '4'))
			return (0);
		else
			a[j++] = av[i++];
	}
	if (j != 16)
		return (0);
	i = 0;
	j = 0;
	while (a[i] != '\0')
	{
		k = 0;
		while (k < 4)
		{
			params[j][k] = a[i] - '0';
			k++;
			i++;
		}
		j++;
	}
	return (1);
}

int main(int argc, char **argv)
{
	int a[4][4];
	int params[4][4];

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (!(ft_valid(argv[1], params)))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	fill_array(a, argv[1]);
	//fill_global(a, params);
	print_table(a);
	write(1, "\n", 1);
	write(1, " CALL SOLVE\n", 12);
	solve(a, params, 0);
	write(1, "\n", 1);
	print_table(a);
	return (0);
}
