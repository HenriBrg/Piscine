/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 22:53:46 by hberger           #+#    #+#             */
/*   Updated: 2019/06/26 15:29:24 by hberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(2, &str[i], 1);
		i++;
	}
}

void	handle_error(char *filename, int error, char *execname)
{
	ft_putstr(basename(execname));
	ft_putstr(": ");
	ft_putstr(basename(filename));
	ft_putstr(": ");
	ft_putstr(strerror(error));
	write(2, "\n", 1);
}

void	handle_file(int fd, char *filename, char *execname)
{
	char	buffer[1];

	while (read(fd, &buffer, 1) > 0)
		write(1, buffer, 1);
	if (read(fd, buffer, 1) == -1)
		handle_error(filename, errno, execname);
	if (close(fd) == -1)
		handle_error(filename, errno, execname);
}

void	handle_input(void)
{
	char buffer[1];

	while (read(STDIN, buffer, 1) > 0)
		write(1, buffer, 1);
}

int		main(int ac, char **av)
{
	int i;
	int fd;

	i = 1;
	if (ac == 1)
		handle_input();
	while (i < ac)
	{
		if (av[i][0] == '-' && av[i][1] == '\0')
		{
			handle_input();
			return (0);
		}
		else if ((fd = open(av[i], O_RDONLY)) == -1)
			handle_error(av[i], errno, av[0]);
		else if (fd != -1)
			handle_file(fd, av[i], av[0]);
		i++;
	}
	return (0);
}
