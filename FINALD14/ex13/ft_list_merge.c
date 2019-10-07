/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 21:56:37 by hberger           #+#    #+#             */
/*   Updated: 2019/06/26 17:33:54 by hberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list *current;

	if (*begin_list1 == 0 && begin_list2 == 0)
		return ;
	if (*begin_list1 == 0)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	current = *begin_list1;
	while (current->next != 0)
		current = current->next;
	current->next = begin_list2;
}
