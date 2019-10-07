/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 18:12:31 by hberger           #+#    #+#             */
/*   Updated: 2019/06/11 20:28:24 by hberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_hexa(char c)
{
	write(1, "\\", 1);
	ft_putchar((c / 16) + 48);
	if ((c % 16) > 9)
		ft_putchar(c + 87);
	else
		ft_putchar(c + 48);
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 0 && str[i] <= 31) || str[i] == 127)
		{
			print_hexa(str[i]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}
