/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 19:30:37 by hberger           #+#    #+#             */
/*   Updated: 2019/06/26 23:50:40 by hberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
	void (*free_fct)(void *))
{
	t_list *previous;
	t_list *current;
	t_list *next;

	if (*begin_list == 0 || begin_list == 0)
		return ;
	current = *begin_list;
	previous = *begin_list;
	while (current)
	{
		next = current->next;
		if ((*cmp)(current->data, data_ref) == 0)
		{
			if (current == *begin_list)
				*begin_list = next;
			previous->next = next;
			free_fct(current->data);
			free(current);
		}
		previous = current;
		current = current->next;
	}
}
