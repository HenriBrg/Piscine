#include "functions.h"

void ft_putstr(char *str)
{
	int i;
	
	i = 0;
	while (str[i] != '\0')
		write(1, &str[i++], 1);
}

void ft_putnbr(int nbr)
{
	ft_putchar(nbr + '0');	
}

void ft_putchar(char c)
{
    write(1, &c, 1);
}   

int ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s1[i]);
}
