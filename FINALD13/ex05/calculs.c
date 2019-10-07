/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:18:22 by hberger           #+#    #+#             */
/*   Updated: 2019/06/24 21:37:50 by hberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	add(int a, int b)
{
	ft_putnbr(a + b);
}

void	sub(int a, int b)
{
	ft_putnbr(a - b);
}

void	mult(int a, int b)
{
	ft_putnbr(a * b);
}

void	div(int a, int b)
{
	if (b == 0)
		return (ft_putstr("Stop : division by zero"));
	ft_putnbr(a / b);
}

void	modulo(int a, int b)
{
	if (b == 0)
		return (ft_putstr("Stop : modulo by zero"));
	ft_putnbr(a % b);
}
