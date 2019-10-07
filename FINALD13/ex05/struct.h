/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 19:40:01 by hberger           #+#    #+#             */
/*   Updated: 2019/06/24 19:41:27 by hberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

void	add(int a, int b);
void	sub(int a, int b);
void	mult(int a, int b);
void	div(int a, int b);
void	modulo(int a, int b);

struct s_opp tab[] = {
	{"+", &add},
	{"-", &sub},
	{"*", &mult},
	{"/", &div},
	{"%", &modulo},
};

#endif
