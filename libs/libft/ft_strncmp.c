/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 11:41:06 by khirsig           #+#    #+#             */
/*   Updated: 2021/08/17 14:47:25 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	index = 0;
	if (n == 0)
		return (0);
	if (s1[0] == 0 || s2[0] == 0)
		return ((unsigned char) s1[0] - s2[0]);
	while (index < n && s1[index] && s2[index])
	{
		if (s1[index] != s2[index])
			return ((unsigned char) s1[index] - s2[index]);
		index++;
	}
	if (index < n)
		return ((unsigned char) s1[index] - s2[index]);
	return (0);
}
