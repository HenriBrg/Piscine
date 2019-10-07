/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 11:31:30 by hberger           #+#    #+#             */
/*   Updated: 2019/06/23 22:31:25 by hberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void				fill_data(struct s_item *tab, char *filename)
{
	int		i;
	int		j;
	int		fd;
	char	buffer[1];

	if ((fd = open(filename, O_RDONLY)) == -1)
		return (ft_putstr("error\n"));
	i = 0;
	j = 0;
	while (read(fd, buffer, 1) > 0)
	{
		if (buffer[0] >= '0' && buffer[0] <= '9')
			tab[i].value[j++] = buffer[0];
		buffer[0] == ':' ? j = 0 : j;
		if (buffer[0] >= 'a' && buffer[0] <= 'z')
			tab[i].word[j++] = buffer[0];
		if (buffer[0] == '\n')
		{
			tab[i].size = ft_strlen(tab[i].value);
			i++;
			j = 0;
		}
	}
}

struct s_item		*alloc(char *filename)
{
	int					l;
	int					fd;
	struct s_item		*tab;
	char				buffer[1];

	if ((fd = open(filename, O_RDONLY)) == -1)
	{
		ft_putstr("**Error\n");
		return (NULL);
	}
	l = 0;
	while (read(fd, buffer, 1) > 0)
	{
		if (buffer[0] == '\n')
			l++;
	}
	if ((tab = malloc(sizeof(t_item) * (l + 1))) == NULL)
		return (NULL);
	close(fd);
	return (tab);
}

int					invalid(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 48 || str[i] > 57)
			return (1);
		i++;
	}
	return (0);
}

int					main(int ac, char **av)
{
	struct s_item *tab;

	(void)av;
	if (ac != 2 || invalid(av[1]))
	{
		ft_putstr("error\n");
		return (0);
	}
	if (av[1][0] == '0')
	{
		ft_putstr("0\n");
		return (0);
	}
	tab = alloc("numbers.dict");
	fill_data(tab, "numbers.dict");
	sort_tab_struct_by_size(tab);
	sort_zero_to_nine_struct_by_ascii(tab);
	sort_ten_to_ninety_struct_by_ascii(tab);
	sort_tab_struct_by_size(tab);
	starting_point(tab, av[1]);
	write(1, "\n", 1);
	return (0);
}
