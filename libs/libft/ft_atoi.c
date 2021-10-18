/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 11:46:49 by khirsig           #+#    #+#             */
/*   Updated: 2021/08/19 09:44:22 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_error(long numb, int minus)
{
	if (numb * minus > INT_MAX || numb * minus < INT_MIN)
	{
		if (numb * minus > INT_MAX)
			ft_putstr_fd("Error\n", 2);
		if (numb * minus < INT_MIN)
			ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
}

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
	ft_error(numb, minus);
	return ((int)(numb * minus));
}
