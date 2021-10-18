/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 13:00:09 by khirsig           #+#    #+#             */
/*   Updated: 2021/08/17 14:46:26 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_makenumb(int count, int original_value, int n)
{
	char	*final_digit;

	final_digit = malloc(sizeof(char) * count + 1);
	if (!final_digit)
		return (0);
	final_digit[count] = '\0';
	count--;
	while (count >= 0)
	{
		if (original_value < 0 && count == 0)
		{
			final_digit[count] = '-';
			break ;
		}
		final_digit[count] = '0' + n % 10;
		n /= 10;
		count--;
	}
	return (final_digit);
}

char	*ft_itoa(int n)
{
	char	*final_digit;
	int		original_value;
	int		count;

	original_value = n;
	count = ft_cntnbr(n);
	if (n == -2147483648)
	{
		final_digit = malloc(sizeof(char) * 13);
		if (!final_digit)
			return (0);
		ft_strcpy(final_digit, "-2147483648");
	}
	else
	{
		if (n < 0)
		{
			n *= -1;
			count++;
		}
		final_digit = ft_makenumb (count, original_value, n);
		if (!final_digit)
			return (0);
	}
	return (final_digit);
}
