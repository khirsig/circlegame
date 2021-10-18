/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 14:12:26 by khirsig           #+#    #+#             */
/*   Updated: 2021/06/26 11:52:50 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*save_lst;

	while (*lst != 0 && (*lst))
	{
		save_lst = (*lst)-> next;
		del((*lst)-> content);
		free(*lst);
		*lst = save_lst;
	}
	lst = 0;
}
