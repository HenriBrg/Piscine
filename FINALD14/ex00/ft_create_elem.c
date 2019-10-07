/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 11:54:33 by hberger           #+#    #+#             */
/*   Updated: 2019/06/25 13:01:37 by hberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list		*ft_create_elem(void *data)
{
	t_list *current;

	if ((current = malloc(sizeof(t_list))) == NULL)
		return (NULL);
	current->next = NULL;
	current->data = data;
	return (current);
}
