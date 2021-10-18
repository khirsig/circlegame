/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:00:35 by khirsig           #+#    #+#             */
/*   Updated: 2021/08/17 14:47:10 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dst;

	dst = malloc(ft_strlen (src) + 1);
	if (dst == 0)
		return (0);
	ft_strcpy (dst, src);
	return (dst);
}
