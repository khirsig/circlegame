/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 13:44:02 by khirsig           #+#    #+#             */
/*   Updated: 2021/08/17 14:47:14 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	length;
	size_t	index;
	size_t	index2;

	length = ft_strlen(dst);
	if (dstsize <= length)
		return (dstsize + ft_strlen(src));
	index = length;
	index2 = 0;
	while (length <= dstsize && src[index2] != '\0' && index < dstsize - 1)
	{
		dst[index] = src[index2];
		index++;
		index2++;
	}
	dst[index] = '\0';
	return (length + ft_strlen(src));
}
