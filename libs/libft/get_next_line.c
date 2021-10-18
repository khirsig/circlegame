/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 14:43:10 by khirsig           #+#    #+#             */
/*   Updated: 2021/07/30 08:26:05 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_return_line(char ***save, char *ret, int i, int is_save)
{
	char	*before_nl;
	char	*after_nl;
	char	*new_ret;

	before_nl = ft_substr(ret, 0, i + 1);
	after_nl = ft_substr(ret, i + 1, ft_strlen(ret) - i - 1);
	if (is_save == TRUE)
	{
		free(**save);
		**save = ft_strdup(after_nl);
		free(after_nl);
		return (before_nl);
	}
	free(ret);
	ret = NULL;
	new_ret = ft_strjoin(**save, before_nl);
	if (after_nl[0] != '\0')
		**save = ft_strdup(after_nl);
	else
		**save = NULL;
	free(after_nl);
	return (new_ret);
}

static void	*ft_save_buff(char ***save, char **ret)
{
	char	*temp;

	if (**save[0] != '\0')
	{
		temp = ft_strdup(**save);
		free(**save);
		**save = ft_strjoin(temp, *ret);
	}
	else
	{
		free(**save);
		**save = ft_strdup(*ret);
		free(*ret);
	}
	return (0);
}

static char	*ft_read_buff(char **save, int fd)
{
	char	*ret;
	int		j;

	ret = malloc(sizeof(char) * BUFFER_SIZE + 1);
	j = read(fd, ret, BUFFER_SIZE);
	if (j == -1)
	{
		free(ret);
		return (NULL);
	}
	ret[j] = '\0';
	while (j != 0 && ft_new_line(ret) == -1)
	{
		ft_save_buff(&save, &ret);
		ret = malloc(sizeof(char) * BUFFER_SIZE + 1);
		j = read(fd, ret, BUFFER_SIZE);
		ret[j] = '\0';
	}
	return (ret);
}

static char	*ft_edge_cases(char **save, char *ret)
{
	int	i;
	int	ll;

	ll = FALSE;
	i = ft_new_line(ret);
	if (ret == NULL)
	{
		free(*save);
		*save = NULL;
		return (NULL);
	}
	if (ret[0] == '\0' && *save[0] != '\0')
		ll = TRUE;
	if (i != -1 && ll == FALSE)
		return (ft_return_line(&save, ret, i, FALSE));
	if (ret)
		free(ret);
	ret = ft_strdup(*save);
	free(*save);
	*save = NULL;
	if (ll == TRUE && ret[0] != '\0')
		return (ret);
	free(ret);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*save[10240];
	char		**point_to_save;
	char		*ret;
	int			i;

	point_to_save = &save[fd];
	if (fd < 0 && BUFFER_SIZE > 0)
		return (NULL);
	if (save[fd] != 0)
		i = ft_new_line(save[fd]);
	else
	{
		save[fd] = ft_strdup("\0");
		i = -1;
	}
	if (i != -1)
		return (ft_return_line(&point_to_save, save[fd], i, TRUE));
	ret = ft_read_buff(&save[fd], fd);
	return (ft_edge_cases(&save[fd], ret));
}
