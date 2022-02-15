/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:33:33 by khirsig           #+#    #+#             */
/*   Updated: 2022/02/15 15:51:22 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/circlegame.h"

void	set_time(t_data *data)
{
	data->seconds_run = GetTime();
	if (data->game_state == GAME)
		data->current_run = data->seconds_run - data->start_time;
	else
		data->current_run = 0;
}
