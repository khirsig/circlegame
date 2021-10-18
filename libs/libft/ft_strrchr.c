/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 14:52:47 by khirsig           #+#    #+#             */
/*   Updated: 2021/06/28 10:27:01 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	index;

	index = ft_strlen(str);
	while (index >= 0)
	{
		if (str[index] == c)
			return ((char *)(str + index));
		index--;
	}
	return (NULL);
}
