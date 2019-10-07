/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 10:16:49 by cjaimes           #+#    #+#             */
/*   Updated: 2019/06/08 13:20:51 by hberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_body(int width)
{
	write(1, "B", 1);
	width--;
	if (width >= 1)
	{
		while (width-- > 1)
			write(1, " ", 1);
		write(1, "B", 1);
	}
	write(1, "\n", 1);
}

void	print_outer(int width, int flag)
{
	int a;

	a = 'B' - flag;
	write(1, &a, 1);
	width--;
	if (width >= 1)
	{
		while (width-- > 1)
			write(1, "B", 1);
		a = 'B' + flag;
		write(1, &a, 1);
	}
	write(1, "\n", 1);
}

void	rush(int x, int y)
{
	if (y-- <= 0 || x <= 0)
		return ;
	print_outer(x, 1);
	if (y >= 1)
	{
		while (y-- > 1)
			print_body(x);
		print_outer(x, -1);
	}
}
