/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 17:29:52 by hberger           #+#    #+#             */
/*   Updated: 2019/06/23 21:18:22 by hberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		ft_strlen(char *str)
{
	int i;

	if (str == 0)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	if (s1 == 0 || s2 == 0)
		return (0);
	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i;

	if (s1 == 0 || s2 == 0)
		return (0);
	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i] && i < n)
		i++;
	return (s1[i] - s2[i]);
}
