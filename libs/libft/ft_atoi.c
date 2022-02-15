/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 11:46:49 by khirsig           #+#    #+#             */
/*   Updated: 2021/11/04 08:11:22 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		count;
	int		minus;
	long	numb;

	minus = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
		minus = -1;
	if (*str == '-' || *str == '+')
		str++;
	count = 0;
	numb = 0;
	while (str[count] >= '0' && str[count] <= '9')
	{
		numb = numb * 10 + str[count] - '0';
		count++;
	}
	return ((int)(numb * minus));
}
