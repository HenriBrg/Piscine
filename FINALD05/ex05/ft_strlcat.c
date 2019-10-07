/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 10:16:29 by hberger           #+#    #+#             */
/*   Updated: 2019/06/18 15:03:15 by hberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int destlen;
	unsigned int srclen;

	destlen = 0;
	while (dest[destlen] != '\0')
		destlen++;
	i = 0;
	srclen = 0;
	while (src[srclen] != '\0')
		srclen++;
	if (size == 0)
		return (srclen);
	srclen = 0;
	while (i + destlen < size - 1 && src[srclen])
	{
		dest[destlen + i] = src[i];
		i++;
		srclen++;
	}
	dest[destlen + i] = '\0';
	while (src[srclen] != '\0')
		srclen++;
	return (size < destlen) ? (srclen + size) : (destlen + srclen);
}
