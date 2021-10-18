/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 12:30:50 by khirsig           #+#    #+#             */
/*   Updated: 2021/06/26 11:58:45 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*save_lst;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	save_lst = *lst;
	while (*lst != 0 && (*lst)-> next)
		*lst = (*lst)-> next;
	(*lst)-> next = new;
	*lst = save_lst;
}
