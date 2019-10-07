/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 13:14:07 by hberger           #+#    #+#             */
/*   Updated: 2019/06/13 12:31:43 by hberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		is_base_valid(char *b)
{
	int i;
	int z;

	i = 0;
	while (b[i])
	{
		if (b[i] == '+' || b[i] == '-' || b[i] <= 32 || b[i] == 127)
			return (0);
		z = i + 1;
		while (b[z])
		{
			if (b[z] == b[i])
				return (0);
			z++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (1);
}

void	print_base(long nbr, char *stringbase, long sizebase)
{
	long i;
	long buffer[1000];

	i = 0;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = nbr * -1;
	}
	while (nbr)
	{
		buffer[i] = nbr % sizebase;
		nbr = nbr / sizebase;
		i++;
	}
	while (--i >= 0)
		ft_putchar(stringbase[buffer[i]]);
}

void	ft_putnbr_base(long nbr, char *base)
{
	long i;
	long b_size;
	long nb;

	nb = nbr;
	if (is_base_valid(base))
	{
		i = 0;
		b_size = 0;
		while (base[b_size])
			b_size++;
		print_base(nb, base, b_size);
	}
}
