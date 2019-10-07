/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 15:04:13 by hberger           #+#    #+#             */
/*   Updated: 2019/06/26 18:17:46 by hberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *current;

	if (*begin_list == 0 || begin_list == 0)
		*begin_list = ft_create_elem(data);
	else
	{
		current = *begin_list;
		while (current->next != 0)
			current = current->next;
		current->next = ft_create_elem(data);
	}
}
