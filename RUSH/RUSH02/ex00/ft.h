/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 17:29:36 by hberger           #+#    #+#             */
/*   Updated: 2019/06/23 22:19:12 by hberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_item
{
	int		size;
	char	word[15];
	char	value[40];
}				t_item;

int				ft_strlen(char *str);
int				ft_strcmp(char *s1, char *s2);
int				ft_strncmp(char *s1, char *s2, unsigned int n);
void			ft_putstr(char *str);
void			handle_triplets(struct s_item *tab, char *triplets);
void			starting_point(struct s_item *tab, char *nbr);
void			show_tab_struct(struct s_item *tab);
void			sort_tab_struct_by_size(struct s_item *tab);
void			sort_zero_to_nine_struct_by_ascii(struct s_item *tab);
void			sort_ten_to_ninety_struct_by_ascii(struct s_item *tab);

#endif
