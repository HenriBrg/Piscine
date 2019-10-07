/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 11:37:46 by cjaimes           #+#    #+#             */
/*   Updated: 2019/06/08 16:12:58 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	affichage(int c, int l, int x, int y)
{
	if (((c + l) == 0) || ((c + l) == (x + y) && (l != 0 && c != 0)))
		ft_putchar('/');
	else if ((c == x && l == 0) || (c == 0 && l == y))
		ft_putchar(92);
	else if ((c != 0 && l != 0) && (c != x && l != y))
		ft_putchar(' ');
	else
		ft_putchar('*');
}

void	rush(int x, int y)
{
	int c;
	int l;

	if ((y < 0) || (x < 0))
		return ;
	c = 0;
	l = 0;
	while (l <= y - 1)
	{
		while (c <= x - 1)
		{
			affichage(c, l, x - 1, y - 1);
			c++;
		}
		c = 0;
		ft_putchar('\n');
		l++;
	}
	ft_putchar('\n');
}
