/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triplets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 23:07:41 by hberger           #+#    #+#             */
/*   Updated: 2019/06/23 22:11:17 by hberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*get_word_by_size_above_hundred(struct s_item *tab, int size)
{
	int i;

	i = 0;
	while (tab[i].size != 0)
	{
		if (tab[i].size == size)
			return (tab[i].word);
		i++;
	}
	return ("");
}

char	*get_units_word_by_cmp(struct s_item *tab, char c)
{
	int i;

	i = 0;
	while (tab[i].size != 0)
	{
		if (tab[i].value[0] == c)
			return (tab[i].word);
		i++;
	}
	return ("");
}

void	handle_twenty_to_ninety_nine(struct s_item *tab, char *triplets)
{
	int i;

	i = 0;
	while (tab[i].size != 0)
	{
		if (tab[i].size == 2 && (triplets[0] == tab[i].value[0]))
		{
			ft_putstr(tab[i].word);
			if (triplets[1] != '0')
			{
				write(1, " ", 1);
				ft_putstr(get_units_word_by_cmp(tab, triplets[1]));
			}
			return ;
		}
		i++;
	}
}

char	*zero_to_nineteen(struct s_item *tab, char *duo)
{
	int i;

	i = 0;
	if (duo[0] == '0')
		return (get_units_word_by_cmp(tab, duo[1]));
	while (tab[i].size != 0)
	{
		if ((ft_strcmp(tab[i].value, duo) == 0))
		{
			return (tab[i].word);
		}
		i++;
	}
	return ("");
}

void	handle_triplets(struct s_item *tab, char *triplets)
{
	int i;

	i = 0;
	while (triplets[i] == '0')
		i++;
	if (i == 2 && triplets[2] != '0')
		return (ft_putstr(get_units_word_by_cmp(tab, triplets[2])));
	while (triplets[i] != '\0')
	{
		if (i == 0)
		{
			ft_putstr(get_units_word_by_cmp(tab, triplets[0]));
			write(1, " ", 1);
			ft_putstr(get_word_by_size_above_hundred(tab, 3));
			write(1, " ", 1);
		}
		if (i++ == 1)
		{
			if (triplets[1] == '0' && triplets[2] == '0')
				break ;
			triplets[1] <= '1' ? ft_putstr(zero_to_nineteen(tab, triplets + 1))
				: handle_twenty_to_ninety_nine(tab, triplets + 1);
			break ;
		}
	}
}
