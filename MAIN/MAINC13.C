#include <stdlib.h>

typedef struct            s_btree
{
	struct s_btree        *left;
	struct s_btree        *right;
	void                *item;
}                        t_btree;

t_btree        *btree_create_node(void *item)
{
	t_btree *node;

	if ((node = malloc((sizeof(t_btree)))) == NULL)
		return (NULL);
	node->left = NULL;
	node->right = NULL;
	node->item = item;
	return (node);
}

#include <string.h>
#include <stdio.h>
void	btree_insert_data(t_btree **root, void *item,
		int (*cmpf)())
{
	t_btree *node;

	if (root == 0)
		return ;
	if (*root == 0)
	{
		*root = btree_create_node(item);
		printf("JE CREE LA ROOT\n");
		return ;
	}
	node = *root;
	if ((*cmpf)(item, node->item) < 0)
	{
		if (node->left == 0)
		{
			node->left = btree_create_node(item);
			printf("JE VAIS A GAUCHE : %s\n", node->item);
		}
		else
			btree_insert_data(&(node->left), item, cmpf);
	}
	else
	{
		if (node->right == 0)
		{
			node->right = btree_create_node(item);
			printf("JE VAIS A DROITE : %s\n", node->item);
		}
		else
			btree_insert_data(&(node->right), item, cmpf);
	}
}

void    *btree_search_item(t_btree *root, void *data_ref,
		int (*cmpf)())
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

void	btree_apply_infix(t_btree *root)
{
	if (root == 0)
		return ;
	btree_apply_infix(root->left);
	printf("%s\n", root->item);
	btree_apply_infix(root->right);
}


int main(int ac, char **av) 
{
	int i;
	t_btree *root;
	
	i = 1;
	while (i < ac)
	{
		btree_insert_data(&root, av[i], &strcmp);
		i++;
	}
	btree_apply_infix(root);
	printf("%s", btree_search_item(root, "4", &strcmp));
	return 0;
}
