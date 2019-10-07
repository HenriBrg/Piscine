/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 13:33:18 by hberger           #+#    #+#             */
/*   Updated: 2019/06/20 15:15:00 by hberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	if (src == 0)
		return (dest);
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

int		memory(char **strs, int size, char *sep)
{
	int i;
	int j;
	int mem;

	i = 0;
	j = 0;
	mem = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			j++;
			mem++;
		}
		i++;
	}
	i = 0;
	while (sep[i] != '\0')
		i++;
	mem = mem + ((size - 1) * i);
	return (mem + 1);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*output;

	if (size == 0)
	{
		output = malloc(sizeof(char));
		output[0] = 0;
		return (output);
	}
	if ((output = malloc(sizeof(char) * memory(strs, size, sep))) == NULL)
		return (NULL);
	i = 0;
	output[i] = '\0';
	while (i < size)
	{
		ft_strcat(output, strs[i]);
		if (i < size - 1)
			ft_strcat(output, sep);
		i++;
	}
	return (output);
}
