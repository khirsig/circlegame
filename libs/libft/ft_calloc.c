/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 14:20:26 by khirsig           #+#    #+#             */
/*   Updated: 2021/08/17 14:46:05 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*new_memory;

	new_memory = malloc(count * size);
	if (!new_memory)
		return (0);
	ft_bzero (new_memory, size * count);
	return (new_memory);
}
