/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:04:58 by khirsig           #+#    #+#             */
/*   Updated: 2021/06/28 10:26:47 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*new_string;
	unsigned int	index;
	unsigned int	length;

	if (!s1 || !s2)
		return (0);
	length = ft_strlen(s1) + ft_strlen(s2);
	new_string = malloc(length + 1);
	if (!new_string)
		return (0);
	index = 0;
	while (index < length && s1[index] != '\0')
	{
		new_string[index] = s1[index];
		index++;
	}
	while (index < length && s2[index - ft_strlen(s1)] != '\0')
	{
		new_string[index] = s2[index - ft_strlen(s1)];
		index++;
	}
	new_string[index] = '\0';
	return (new_string);
}
