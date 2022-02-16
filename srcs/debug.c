/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:24:46 by khirsig           #+#    #+#             */
/*   Updated: 2022/02/16 11:29:27 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/circlegame.h"

void	debug_mode(t_data *data)
{
	char	*temp;

	if (data->debug == FALSE && IsKeyPressed(KEY_TAB))
		data->debug = TRUE;
	else if (data->debug == TRUE && IsKeyPressed(KEY_TAB))
		data->debug = FALSE;
	if (data->debug == TRUE)
	{
		temp = ft_itoa(GetFPS());
		DrawText(temp, 10, 10, 20, DARKGRAY);
		free(temp);
	}
}