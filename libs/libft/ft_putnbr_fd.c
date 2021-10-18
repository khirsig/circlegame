/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 15:50:31 by khirsig           #+#    #+#             */
/*   Updated: 2021/06/24 17:15:44 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_write_numb(int original_value, char digit[50], int count, int f)
{
	while (count != -1 || original_value == 0)
	{
		if (original_value == -2147483648)
		{
			write(f, "-2147483648", 11);
			break ;
		}
		if (original_value == 0)
		{
			write(f, "0", 1);
			break ;
		}
		write(f, &digit[count], 1);
		count--;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int		count;
	char	digit[50];
	int		original_value;
	char	*digits;

	count = 0;
	original_value = n;
	if (n < 0)
		n *= -1;
	while (n != 0)
	{
		digit[count] = '0' + n % 10;
		n /= 10;
		count++;
	}
	if (original_value < 0)
	{
		digit[count] = '-';
		count++;
	}
	count--;
	digits = digit;
	ft_write_numb(original_value, digits, count, fd);
}
