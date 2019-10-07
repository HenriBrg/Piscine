/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 11:58:13 by hberger           #+#    #+#             */
/*   Updated: 2019/06/07 11:08:47 by hberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char chiffre)
{
	write(1, &chiffre, 1);
}

void	ft_print_numbers(void)
{
	int chiffre;

	chiffre = '0';
	while (chiffre <= '9')
	{
		ft_putchar(chiffre);
		chiffre++;
	}
}
