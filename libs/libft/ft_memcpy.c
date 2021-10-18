/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:28:17 by khirsig           #+#    #+#             */
/*   Updated: 2021/06/24 16:51:34 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			index;
	unsigned char	*c;
	unsigned char	*d;

	index = 0;
	c = (unsigned char *)dest;
	d = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	while (index < n)
	{
		c[index] = d[index];
		index++;
	}
	return (dest);
}
