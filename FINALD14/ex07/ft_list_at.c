/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 17:49:12 by hberger           #+#    #+#             */
/*   Updated: 2019/06/26 11:44:48 by hberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list		*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;
	t_list			*current;

	i = 0;
	current = begin_list;
	while (current && i < nbr)
	{
		i++;
		current = current->next;
	}
	return ((i == nbr) ? current : NULL);
}
