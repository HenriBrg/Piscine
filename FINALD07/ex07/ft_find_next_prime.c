/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 20:53:04 by hberger           #+#    #+#             */
/*   Updated: 2019/06/14 11:11:00 by hberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_prime(int nb)
{
	int i;

	if (nb == 0 || nb == 1)
		return (0);
	if (nb == 2)
		return (1);
	i = 2;
	while (i < nb / i)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (nb);
}

int		ft_find_next_prime(int nb)
{
	int i;
	int output;

	if (nb < 0)
		return (2);
	if (nb == 0 || nb == 1 || nb == 2)
		return (2);
	i = 0;
	output = 0;
	if (nb % 2 == 0)
		nb++;
	while (!(output = ft_prime(nb + i)))
		i += 2;
	return (output);
}
