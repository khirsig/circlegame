/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 11:10:41 by khirsig           #+#    #+#             */
/*   Updated: 2021/06/24 16:36:42 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			index;
	unsigned char	*c;
	unsigned char	*d;

	index = 0;
	c = (unsigned char *)dst;
	d = (unsigned char *)src;
	if (!dst && !src)
		return (0);
	while (len > 0 && dst > src)
	{
		c[len - 1] = d[len - 1];
		len--;
	}
	while (index < len && dst <= src)
	{
		c[index] = d[index];
		index++;
	}
	return (dst);
}
