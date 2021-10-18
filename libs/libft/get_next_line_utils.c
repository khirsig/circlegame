/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 14:43:27 by khirsig           #+#    #+#             */
/*   Updated: 2021/08/17 14:47:59 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_new_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (i);
	return (-1);
}

int	ft_count_lines(char *file)
{
	char	*str;
	int		count;
	int		fd;

	count = 0;
	fd = open(file, O_RDONLY);
	if (!fd)
		return (0);
	str = get_next_line(fd);
	count++;
	while (str != NULL)
	{
		str = get_next_line(fd);
		count++;
	}
	free(str);
	close(fd);
	return (count);
}
