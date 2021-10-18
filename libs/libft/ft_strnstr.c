/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 16:45:29 by khirsig           #+#    #+#             */
/*   Updated: 2021/10/15 12:59:08 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (haystack == NULL)
		return (0);
	if (!ft_strlen(needle))
		return ((char *) haystack);
	while (i < len && haystack[i] != 0)
	{
		j = 0;
		while (needle[j] == haystack[i + j]
			&& haystack[i + j] != '\0' && i + j < len)
			j++;
		if (needle[j] == '\0')
			return ((char *)(haystack + i));
		i++;
	}
	return (0);
}
