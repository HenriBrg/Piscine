/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:53:23 by hberger           #+#    #+#             */
/*   Updated: 2019/06/26 00:01:46 by hberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int		ft_list_size(t_list *begin_list)
{
	int			i;
	t_list		*current;

	i = 0;
	current = begin_list;
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);
}
