/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 15:10:59 by hberger           #+#    #+#             */
/*   Updated: 2019/06/27 16:23:27 by hberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
		int (*cmpf)(void *, void *))
{
	t_btree *node;

	node = NULL;
	if (root == 0)
		return (NULL);
	node = btree_search_item(root->left, data_ref, cmpf);
	if (node)
		return (node);
	if (cmpf(node->item, data_ref) == 0)
		return (root->item);
	node = btree_search_item(node->right, data_ref, cmpf);
	return (node);
}
