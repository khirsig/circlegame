/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 13:14:25 by khirsig           #+#    #+#             */
/*   Updated: 2021/08/17 14:47:19 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	index;

	index = 0;
	if (size == 0)
		return (ft_strlen(src));
	if (!dst)
		return (0);
	while (index < size - 1 && src[index] != '\0')
	{
		dst[index] = src[index];
		index++;
	}
	if (size != 0)
		dst[index] = '\0';
	return (ft_strlen(src));
}
