#include "ft_list.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
void (*free_fct)(void *));

t_list		*ft_create_elem(void *data)
{
	t_list *current;

	if ((current = malloc(sizeof(t_list))) == NULL)
		return (NULL);
	current->next = NULL;
	current->data = data;
	return (current);
}

void show(t_list **begin_list)
{
	t_list *current;
	current = *begin_list;
	while (current)
	{
		printf("%s\n", current->data);
		current = current->next;
	}
}

int main()
{
	t_list *one;
	t_list *two;
	t_list *three;
	t_list **begin;
	begin = &one;
	one = ft_create_elem("ONE");
	two = ft_create_elem("TWO");
	three = ft_create_elem("THREE");
	ft_list_remove_if(begin, "TWO", &strcmp, &free);
	return (0);
}
