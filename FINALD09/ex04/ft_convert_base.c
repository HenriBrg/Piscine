/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 10:54:24 by hberger           #+#    #+#             */
/*   Updated: 2019/06/20 15:11:18 by hberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

long int	ft_atoi_base(char *str, char *base, int sign);
int			check(char *base, char c);

int			ft_strlen(char *str)
{
	int i;

	if (str == 0)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int			is_base_valid(char *str)
{
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-' || str[i] == ' ')
			return (0);
		j = i + 1;
		while (str[j])
		{
			if (str[j] == str[i])
				return (-1);
			j++;
		}
		i++;
	}
	return (i);
}

char		*cv(long int nb, long int length, long int base_len, char *base_to)
{
	char *nbr;

	if ((nbr = (char*)malloc(sizeof(char) * (length))) == NULL)
		return (NULL);
	if (nb == 0)
	{
		nbr[0] = base_to[0];
		return (nbr);
	}
	if (nb < 0)
	{
		nb = nb * -1;
		nbr[0] = '-';
		length += 1;
	}
	nbr[length -= 2] = '\0';
	while (nb > 0)
	{
		nbr[length] = base_to[nb % base_len];
		nb = nb / base_len;
		length--;
	}
	if (check(base_to, nbr[ft_strlen(nbr) - 1]))
		nbr[ft_strlen(nbr) - 1] = '\0';
	return (nbr);
}

char		*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long int	i;
	long int	nb;
	long int	size;
	long int	nb_size;

	if (is_base_valid(base_from) < 2 || is_base_valid(base_to) < 2)
		return (NULL);
	i = 0;
	size = is_base_valid(base_from);
	nb = ft_atoi_base(nbr, base_from, size);
	nb_size = 0;
	size = is_base_valid(base_to);
	i = nb;
	while (i != 0)
	{
		i = i / size;
		nb_size++;
	}
	return (cv(nb, nb_size + 1, size, base_to));
}
