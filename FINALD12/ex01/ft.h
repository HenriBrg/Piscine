/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 13:38:19 by hberger           #+#    #+#             */
/*   Updated: 2019/06/26 14:41:08 by hberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <libgen.h>

# include <stdio.h>

# define STDIN 0

void	ft_putstr(char *str);

#endif
