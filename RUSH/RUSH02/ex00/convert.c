/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 20:10:07 by hberger           #+#    #+#             */
/*   Updated: 2019/06/23 18:10:25 by hberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*fill_triplet(char *nbr, int nbsize)
{
	int		i;
	int		j;
	int		offset;
	char	*newnbr;

	offset = 3 - (nbsize % 3);
	if ((newnbr = malloc(sizeof(char) * (nbsize + offset + 1))) == NULL)
		return (NULL);
	i = 0;
	while (offset)
	{
		newnbr[i] = '0';
		i++;
		offset--;
	}
	j = 0;
	while (nbr[j] != '\0')
	{
		newnbr[i + j] = nbr[j];
		j++;
	}
	return (newnbr);
}

char	**split_triplets(char *nbr, int triplets)
{
	int		i;
	int		j;
	int		k;
	char	**t;

	if ((t = malloc(sizeof(char*) * (triplets + 1))) == NULL)
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	while (triplets > 0)
	{
		if ((t[i] = malloc(sizeof(char) * 4)) == NULL)
			return (NULL);
		t[i][j] = nbr[k];
		t[i][j + 1] = nbr[k + 1];
		t[i][j + 2] = nbr[k + 2];
		t[i][j + 3] = 0;
		i++;
		k += 3;
		triplets--;
	}
	t[i] = 0;
	return (t);
}

void	handle_triplets_relation(struct s_item *tab, int pos)
{
	if (1)
	{
		write(1, " ", 1);
		ft_putstr(tab[29 + pos - 2].word);
		write(1, " ", 1);
	}
}

int		check_if_not_full_zero(char *triplet)
{
	int i;

	i = 0;
	while (triplet[i] != '\0')
	{
		if (triplet[i] != '0')
			return (1);
		i++;
	}
	return (0);
}

void	starting_point(struct s_item *tab, char *nbr)
{
	int		i;
	int		nbsize;
	int		triplets;
	int		triplet_pos;
	char	**splitted_triplets;

	(void)tab;
	nbsize = ft_strlen(nbr);
	if (nbsize % 3 != 0)
		nbr = fill_triplet(nbr, nbsize);
	triplets = ft_strlen(nbr) / 3;
	splitted_triplets = split_triplets(nbr, triplets);
	i = 0;
	triplet_pos = triplets;
	while (splitted_triplets[i] != 0)
	{
		handle_triplets(tab, splitted_triplets[i]);
		if (i != 0 && splitted_triplets[i + 1] != 0)
			write(1, " ", 1);
		if (i < triplets - 1 && (check_if_not_full_zero(splitted_triplets[i])))
			handle_triplets_relation(tab, triplet_pos);
		triplet_pos--;
		i++;
	}
}
