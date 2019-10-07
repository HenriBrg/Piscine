/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 16:15:49 by hberger           #+#    #+#             */
/*   Updated: 2019/06/24 21:44:36 by hberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int increasing;
	int decreasing;

	if (length <= 2)
		return (1);
	i = 1;
	increasing = 1;
	decreasing = 1;
	while (i < length)
	{
		if (f(tab[i], tab[i - 1]) < 0)
			increasing = 0;
		if (f(tab[i], tab[i - 1]) > 0)
			decreasing = 0;
		if (!increasing && !decreasing)
			return (0);
		i++;
	}
	return (1);
}
