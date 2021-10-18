/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 14:34:08 by khirsig           #+#    #+#             */
/*   Updated: 2021/08/17 14:47:06 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = ft_strlen(str) + 1;
	while (i < len)
	{
		if (str[i] == c)
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}
