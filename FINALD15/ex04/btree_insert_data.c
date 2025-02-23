/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 13:54:35 by hberger           #+#    #+#             */
/*   Updated: 2019/06/27 18:07:13 by hberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item,
		int (*cmpf)(void *, void *))
{
	t_btree *node;

	if (root == 0)
		return ;
	if (*root == 0)
	{
		*root = btree_create_node(item);
		return ;
	}
	node = *root;
	if ((*cmpf)(item, node->item) < 0)
	{
		if (node->left == 0)
			node->left = btree_create_node(item);
		else
			btree_insert_data(&(node->left), item, cmpf);
	}
	else
	{
		if (node->right == 0)
			node->right = btree_create_node(item);
		else
			btree_insert_data(&(node->right), item, cmpf);
	}
}
