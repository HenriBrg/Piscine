/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 13:24:57 by hberger           #+#    #+#             */
/*   Updated: 2019/06/25 14:50:00 by hberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *current;

	if (begin_list == 0)
		*begin_list = ft_create_elem(data);
	else
	{
		current = ft_create_elem(data);
		current->next = *begin_list;
		*begin_list = current;
	}
}
