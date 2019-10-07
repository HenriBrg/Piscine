/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:14:53 by hberger           #+#    #+#             */
/*   Updated: 2019/06/24 19:41:42 by hberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>

typedef struct	s_opp
{
	char *symbol;
	void (*function)(int, int);
}				t_opp;

void			add(int a, int b);
void			sub(int a, int b);
void			mult(int a, int b);
void			div(int a, int b);
void			modulo(int a, int b);

void			ft_putchar(char c);
void			ft_putnbr(int nb);
int				ft_atoi(char *str);
void			ft_putstr(char *str);
int				ft_strcmp(char *s1, char *s2);

#endif
