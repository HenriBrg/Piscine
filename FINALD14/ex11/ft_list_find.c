/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 19:16:04 by hberger           #+#    #+#             */
/*   Updated: 2019/06/26 12:43:19 by hberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list		*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list *current;

	current = begin_list;
	while (current)
	{
		if ((*cmp)(current->data, data_ref) == 0)
			return (current);
		current = current->next;
	}
	return (NULL);
}
