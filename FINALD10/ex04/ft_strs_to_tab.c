/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 23:42:06 by hberger           #+#    #+#             */
/*   Updated: 2019/06/20 17:43:26 by hberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int						ft_strlen(char *str)
{
	int i;

	if (str == 0)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char					*ft_strdup(char *src)
{
	int		i;
	char	*output;

	i = 0;
	while (src[i] != '\0')
		i++;
	if ((output = malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		output[i] = src[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}

struct s_stock_str		*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str *tab;

	tab = malloc(sizeof(t_stock_str) * (ac + 1));
	if (tab == NULL)
		return (NULL);
	tab[ac].str = 0;
	while (--ac >= 0)
	{
		tab[ac].size = ft_strlen(av[ac]);
		tab[ac].str = av[ac];
		tab[ac].copy = ft_strdup(av[ac]);
	}
	return (tab);
}
