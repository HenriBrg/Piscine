/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 18:40:11 by hberger           #+#    #+#             */
/*   Updated: 2019/06/21 12:24:52 by hberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		check(char *charset, char c)
{
	int i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int		words(char *str, char *charset)
{
	int i;
	int x;

	i = 0;
	x = 0;
	while (str[i] != '\0')
	{
		if (check(charset, str[i]))
		{
			x++;
			while (check(charset, str[i]))
				i++;
		}
		else
			i++;
	}
	return (x + 1);
}

char	*copy(char *str, char *charset)
{
	int		i;
	char	*output;

	i = 0;
	while (check(charset, str[i]))
		i++;
	if ((output = (char*)malloc(sizeof(char) * (i + 75))) == NULL)
		return (NULL);
	i = 0;
	output[i] = '\0';
	while (str[i] != '\0')
	{
		if (check(charset, str[i]))
		{
			while (check(charset, str[i]))
			{
				output[i] = str[i];
				i++;
			}
			output[i] = '\0';
		}
		else
			i++;
	}
	return (output);
}

char	**empty_charset(char *str)
{
	int		i;
	char	**result;

	i = 0;
	while (str[i] != '\0')
		i++;
	if ((result = (char**)malloc(sizeof(char*))) == NULL)
		return (NULL);
	if ((result[0] = (char*)malloc(sizeof(char) * (i + 75))) == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		result[0][i] = str[i];
		i++;
	}
	result[0][i] = 0;
	result[1] = 0;
	return (result);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		x;
	char	**result;

	if (*charset == '\0' || charset == 0)
		return (empty_charset(str));
	if ((result = malloc(sizeof(char*) * words(str, charset))) == NULL)
		return (NULL);
	i = 0;
	x = 0;
	while (str[i] != '\0')
	{
		if (check(charset, str[i]))
		{
			result[x] = copy(str + i, charset);
			while (check(charset, str[i]))
				i++;
			x++;
		}
		else
			i++;
	}
	result[x] = 0;
	return (result);
}
