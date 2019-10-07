/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_born.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaugry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 17:26:57 by juaugry           #+#    #+#             */
/*   Updated: 2019/06/16 21:00:23 by hberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_check_up(int t[4][4], int views[4][4], int i, int j)
{
	int max;
	int count;
	int k;

	max = 0;
	count = 0;
	k = 0;
	while (k <= 3)
	{
		if (max <= t[i][k])
		{
			max = t[i][k];
			count++;
		}
		k++;
	}
	if (count != views[i][j])
		return (0);
	return (1);
}

int		ft_check_down(int t[4][4], int views[4][4], int i, int j)
{
	int max;
	int count;
	int k;

	max = 0;
	count = 0;
	k = 3;
	while (k >= 0)
	{
		if (max <= t[i][k])
		{
			max = t[i][k];
			count++;
		}
		k--;
	}
	if (count != views[i][j])
		return (0);
	return (1);
}

int		ft_check_left(int t[4][4], int views[4][4], int i, int j)
{
	int max;
	int count;
	int k;

	max = 0;
	count = 0;
	k = 0;
	while (k <= 3)
	{
		if (max <= t[k][j])
		{
			max = t[k][j];
			count++;
		}
		k++;
	}
	if (count != views[i][j])
		return (0);
	return (1);
}

int		ft_check_right(int t[4][4], int views[4][4], int i, int j)
{
	int max;
	int count;
	int k;

	max = 0;
	count = 0;
	k = 3;
	while (k >= 0)
	{
		if (max <= t[k][j])
		{
			max = t[k][j];
			count++;
		}
		k--;
	}
	if (count != views[i][j])
		return (0);
	return (1);
}


