/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 15:53:25 by hberger           #+#    #+#             */
/*   Updated: 2019/06/24 21:47:17 by hberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int i;
	int *output;

	i = 0;
	if ((output = malloc(sizeof(int) * length + 1)) == NULL)
		return (NULL);
	while (i < length)
	{
		output[i] = f(tab[i]);
		i++;
	}
	return (output);
}
