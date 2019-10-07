/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 17:27:36 by hberger           #+#    #+#             */
/*   Updated: 2019/06/26 17:39:23 by hberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list *current_one;
	t_list *current_two;
	t_list *next;

	current_one = *begin_list;
	while (current_one)
	{
		current_two = *begin_list;
		while (current_two->next)
		{
			if ((*cmp)(current_two->data, current_two->next->data) > 0)
			{
				next = current_two->data;
				current_two->data = current_two->next->data;
				current_two->next->data = next;
			}
			current_two = current_two->next;
		}
		current_one = current_one->next;
	}
}
