/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 16:13:02 by khirsig           #+#    #+#             */
/*   Updated: 2021/10/07 12:47:05 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_strarrlen(char const *s, char c)
{
	int	index;
	int	counter;
	int	c_true;

	index = 1;
	counter = 0;
	c_true = 1;
	while (s[index] != 0)
	{
		if (s[index] == c && s[index - 1] != c)
			c_true = 1;
		if (c_true == 1 && s[index] != c)
		{
			counter++;
			c_true = 0;
		}
		index++;
	}
	return (counter);
}

static int	ft_splitlen(char const *s, char c, unsigned int k)
{
	int	counter;

	counter = 0;
	while (s[k] && s[k] == c)
		k++;
	while (s[k] && s[k] != c)
	{
		k++;
		counter++;
	}
	counter++;
	return (counter);
}

static void	ft_split_me(char const *s, char c, char **new_str)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	k = 0;
	while (i < ft_strarrlen(s, c))
	{
		j = 0;
		new_str[i] = malloc(sizeof(char) * ft_splitlen(s, c, k));
		while (s[k] == c)
			k++;
		while (s[k] != '\0' && s[k] != c)
		{
			new_str[i][j] = s[k];
			j++;
			k++;
		}
		new_str[i][j] = '\0';
		i++;
	}
	new_str[i] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**new_str;

	if (!s)
		return (0);
	if (s[0] == 0)
	{
		new_str = malloc(1 * sizeof(char *));
		new_str[0] = 0;
		return (new_str);
	}
	if (!ft_strchr(s, c))
	{
		new_str = malloc(2 * sizeof(char *));
		*new_str = malloc(ft_strlen(s) + 1);
		ft_strlcpy(*new_str, s, ft_strlen(s) + 1);
		new_str[1] = 0;
		return (new_str);
	}
	new_str = malloc(sizeof(char *) * (ft_strarrlen(s, c) + 1));
	if (!new_str)
		return (0);
	ft_split_me(s, c, new_str);
	return (new_str);
}
