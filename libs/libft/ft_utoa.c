/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 10:41:21 by khirsig           #+#    #+#             */
/*   Updated: 2021/07/06 08:30:36 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utoa(long long u)
{
	char	*final_digit;
	int		count;

	count = ft_cntnbr(u);
	final_digit = malloc(count + 1);
	if (!final_digit)
		return (0);
	final_digit[count] = 0;
	count--;
	while (count >= 0)
	{
		final_digit[count] = '0' + u % 10;
		u /= 10;
		count--;
	}
	return (final_digit);
}
