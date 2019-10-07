/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 17:50:27 by hberger           #+#    #+#             */
/*   Updated: 2019/06/24 21:01:11 by hberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "struct.h"

void	compute(int a, char *operator, int b)
{
	int i;
	int size;

	i = 0;
	size = sizeof(tab) / sizeof(*tab);
	while (i < size)
	{
		if (ft_strcmp(tab[i].symbol, operator) == 0)
		{
			tab[i].function(a, b);
			return ;
		}
		i++;
	}
}

int		main(int argc, char **av)
{
	int a;
	int b;

	if (argc != 4)
		return (0);
	a = ft_atoi(av[1]);
	b = ft_atoi(av[3]);
	if (av[2][0] != '+' && av[2][0] != '-' && av[2][0] != '*'
			&& av[2][0] != '/' && av[2][0] != '%')
	{
		write(1, "0\n", 2);
		return (0);
	}
	compute(a, av[2], b);
	write(1, "\n", 1);
	return (0);
}
