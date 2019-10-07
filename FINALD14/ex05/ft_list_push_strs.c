/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 15:33:56 by hberger           #+#    #+#             */
/*   Updated: 2019/06/27 11:20:35 by hberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list		*ft_list_push_strs(int size, char **strs)
{
	t_list		*begin;
	t_list		*current;
	t_list		*previous;

	if (size == 0)
		return (0);
	begin = 0;
	while (--size >= 0)
	{
		current = ft_create_elem(strs[size]);
		if (begin != 0)
			previous->next = current;
		else
			begin = current;
		previous = current;
	}
	return (begin);
}
