/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:34:22 by khirsig           #+#    #+#             */
/*   Updated: 2021/10/18 09:50:31 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minigame.h"

static void	mirror_ice_mode(t_data *data)
{
	data->ball_color = DARKGREEN;
	data->special_mode = MIRROR_ICE;
	data->ball_size = 25;
}

static void	ice_mode(t_data *data)
{
	data->ball_color = SKYBLUE;
	data->special_mode = ICE;
	data->ball_size = 25;
}

static void	big_mode(t_data *data)
{
	data->ball_color = MAROON;
	data->special_mode = BIG;
	data->ball_size = 40;
}

static void	reverse_mode(t_data *data)
{
	data->ball_color = LIME;
	data->special_mode = REVERSE;
	data->ball_size = 25;
}

static void	normal_mode(t_data *data)
{
	data->ball_color = MAROON;
	data->special_mode = NORMAL;
	data->ball_size = 25;
}

void	special_modes(t_data *data)
{
	int rnd;

	if (data->seconds_run % 10 == 0 && data->last_modeswap != data->seconds_run)
	{
		rnd = GetRandomValue(1, 5);
		while (data->special_mode == rnd)
			rnd = GetRandomValue(1, 5);
		if (rnd == 1)
			normal_mode(data);
		if (rnd == 2)
			reverse_mode(data);
		if (rnd == 3)
			big_mode(data);
		if (rnd == 4)
			ice_mode(data);
		if (rnd == 5)
			mirror_ice_mode(data);
		data->last_modeswap = data->seconds_run;
	}
	return ;
}