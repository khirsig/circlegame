/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 10:28:07 by khirsig           #+#    #+#             */
/*   Updated: 2021/06/28 10:50:07 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	index;
	char			*substr;

	index = 0;
	if (!s)
		return (0);
	substr = malloc(len + 1);
	if (!substr)
		return (0);
	if (start < ft_strlen(s))
	{
		while (index < len && s[start])
		{
			substr[index] = s[start];
			index++;
			start++;
		}
	}
	substr[index] = '\0';
	return (substr);
}
