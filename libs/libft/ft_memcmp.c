/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 11:43:27 by khirsig           #+#    #+#             */
/*   Updated: 2021/08/17 14:46:46 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			index;
	unsigned char	*c1;
	unsigned char	*c2;

	index = 0;
	c1 = (unsigned char *) s1;
	c2 = (unsigned char *) s2;
	while (index < n)
	{
		if (c1[index] != c2[index])
			return (c1[index] - c2[index]);
		index++;
	}
	return (0);
}
