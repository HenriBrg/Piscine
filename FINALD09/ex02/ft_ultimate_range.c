/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 13:33:30 by hberger           #+#    #+#             */
/*   Updated: 2019/06/18 13:33:33 by hberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int i;
	int *tab;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	i = 0;
	tab = (int*)malloc((max - min) * sizeof(*tab));
	if (tab == NULL)
		return (-1);
	i = 0;
	while (min < max)
	{
		tab[i] = min;
		min++;
		i++;
	}
	*range = tab;
	return (i);
}
