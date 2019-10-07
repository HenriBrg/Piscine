/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 16:49:45 by hberger           #+#    #+#             */
/*   Updated: 2019/06/26 23:03:09 by hberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list *tmp;
	t_list *current;

	if (begin_list == 0)
		return ;
	current = begin_list;
	while (current)
	{
		tmp = current->next;
		(*free_fct)(current->data);
		free(current);
		current = tmp;
	}
}
