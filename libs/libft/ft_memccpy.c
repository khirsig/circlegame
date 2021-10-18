/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 10:09:45 by khirsig           #+#    #+#             */
/*   Updated: 2021/08/17 14:46:41 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			index;
	unsigned char	*e;
	unsigned char	*d;

	index = 0;
	e = (unsigned char *) dst;
	d = (unsigned char *) src;
	while (index < n)
	{
		e[index] = d[index];
		if (d[index] == (unsigned char) c)
		{
			return ((unsigned char *)(e + index + 1));
		}
		index++;
	}
	return (NULL);
}
