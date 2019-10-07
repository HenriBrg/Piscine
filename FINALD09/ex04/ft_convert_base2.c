/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:06:37 by hberger           #+#    #+#             */
/*   Updated: 2019/06/20 15:11:22 by hberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			check(char *base, char c)
{
	int i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int			char_value_from_base(char c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

long int	ft_atoi_base(char *str, char *base, long int size)
{
	long int	i;
	long int	sign;
	long int	result;

	i = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		str[i] == '-' ? sign = sign * -1 : sign;
		i++;
	}
	result = 0;
	while (str[i] != '\0' && !check(base, str[i]))
	{
		result = result * size + char_value_from_base(str[i], base);
		i++;
	}
	return (result * sign);
}
