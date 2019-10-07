/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 13:33:43 by hberger           #+#    #+#             */
/*   Updated: 2019/06/18 13:33:47 by hberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		i;
	int		*my_array;

	if (min >= max)
		return (NULL);
	my_array = (int *)malloc((max - min) * sizeof(int));
	if (my_array == NULL)
		return (NULL);
	i = 0;
	while (min < max)
	{
		my_array[i] = min;
		min++;
		i++;
	}
	return (my_array);
}
