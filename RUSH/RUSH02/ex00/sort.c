/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 21:37:00 by hberger           #+#    #+#             */
/*   Updated: 2019/06/23 22:17:33 by hberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	sort_tab_struct_by_size(struct s_item *tab)
{
	int				i;
	struct s_item	tmp;

	i = 0;
	while (i < 41)
	{
		if (tab[i].size > tab[i + 1].size && tab[i + 1].size != 0)
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

void	sort_zero_to_nine_struct_by_ascii(struct s_item *tab)
{
	int				i;
	struct s_item	tmp;

	i = 0;
	while (i <= 8)
	{
		if (ft_strcmp(tab[i].value, tab[i + 1].value) > 0)
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

void	sort_ten_to_ninety_struct_by_ascii(struct s_item *tab)
{
	int				i;
	struct s_item	tmp;

	i = 9;
	while (i <= 18)
	{
		if (ft_strcmp(tab[i].value, tab[i + 1].value) > 0)
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}
