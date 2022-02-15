/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 12:10:41 by jhagedor          #+#    #+#             */
/*   Updated: 2022/02/15 11:19:11 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static char	*if_newline(char **save, char *line, int i)
// {
// 	char	*tmp;

// 	line = ft_substr(*save, 0, i + 1);
// 	tmp = ft_strdup(&((*save)[i + 1]));
// 	free(*save);
// 	*save = tmp;
// 	if ((*save)[0] == '\0')
// 	{
// 		free(*save);
// 		*save = NULL;
// 	}
// 	return (line);
// }

// static char	*ft_return(char **save, int bytes)
// {
// 	int		i;
// 	char	*line;

// 	line = NULL;
// 	if (bytes == 0 && *save == NULL)
// 		return (NULL);
// 	i = 0;
// 	while ((*save)[i] != '\n' && (*save)[i] != '\0')
// 		i++;
// 	if ((*save)[i] == '\n')
// 		line = if_newline(save, line, i);
// 	else
// 	{
// 		line = ft_strdup(*save);
// 		free(*save);
// 		*save = NULL;
// 	}
// 	return (line);
// }

// static char	*ft_joinstuff(char *save, char *buff)
// {
// 	char	*temp;

// 	temp = ft_strjoin(save, buff);
// 	free(save);
// 	save = temp;
// 	return (save);
// }

// char	*get_next_line_2(int fd)
// {
// 	static char	*save;
// 	char		buff[1 + 1];
// 	int			bytes;

// 	bytes = 1;
// 	if (fd < 0)
// 		return (NULL);
// 	while (bytes > 0)
// 	{
// 		bytes = read(fd, buff, 1);
// 		if (bytes == 0)
// 			break ;
// 		if (bytes > 0)
// 			buff[bytes] = '\0';
// 		else if (bytes == -1)
// 			return (NULL);
// 		if (!save)
// 			save = ft_strdup(buff);
// 		else
// 			save = ft_joinstuff(save, buff);
// 		if (ft_strchr(save, '\n'))
// 			break ;
// 	}
// 	return (ft_return(&save, bytes));
// }

static char	*str_append_chr(char *str, char append)
{
	char	*new_str;
	int		i;

	if (str == NULL)
		return (NULL);
	new_str = malloc(ft_strlen(str) + 2);
	if (new_str != NULL)
	{
		i = 0;
		while (str[i])
		{
			new_str[i] = str[i];
			i++;
		}
		new_str[i] = append;
		new_str[i + 1] = '\0';
	}
	free(str);
	return (new_str);
}

static char	*minishell_gnl_free_line(char *line)
{
	free(line);
	return (NULL);
}

char	*get_next_line_2(int fd)
{
	char	*line;
	char	buffer;
	int		check;

	line = ft_strdup("");
	if (line == NULL)
		return (NULL);
	check = read(fd, &buffer, 1);
	if (check == -1 || check == 0)
		return (minishell_gnl_free_line(line));
	while (check > 0)
	{
		line = str_append_chr(line, buffer);
		if (line == NULL)
			return (NULL);
		if (buffer == '\n')
			return (line);
		check = read(fd, &buffer, 1);
	}
	if (check == -1)
		return (minishell_gnl_free_line(line));
	return (line);
}