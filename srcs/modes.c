/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:34:22 by khirsig           #+#    #+#             */
/*   Updated: 2022/02/15 15:45:59 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/circlegame.h"

static void warp_mode(t_data *data)
{
	data->player.color = ORANGE;
	data->special_mode = WARP;
	data->player.size = 25;
	data->player.speed = 0.0f;
}

static void	slow_mode(t_data *data)
{
	data->player.color = BROWN;
	data->special_mode = SLOW;
	data->player.size = 25;
	data->player.speed = 2.0f;
}

static void	speed_mode(t_data *data)
{
	data->player.color = BLUE;
	data->special_mode = SPEED;
	data->player.size = 25;
	data->player.speed = 10.0f;
}

static void	growth_mode(t_data *data)
{
	data->player.color = GROWTH_PURPLE;
	data->special_mode = GROWTH;
	data->player.size = 25;
	data->player.growth_min = 15;
	data->player.growth_max = 40;
	data->player.speed = 5.0f;
}

static void	mirror_ice_mode(t_data *data)
{
	data->player.color = MIRROR_ICE_GREEN;
	data->special_mode = MIRROR_ICE;
	data->player.size = 25;
	data->player.speed = 5.0f;
}

static void	ice_mode(t_data *data)
{
	data->player.color = SKYBLUE;
	data->special_mode = ICE;
	data->player.size = 25;
	data->player.speed = 5.0f;
}

static void	big_mode(t_data *data)
{
	data->player.color = MAROON;
	data->special_mode = BIG;
	data->player.size = 40;
	data->player.speed = 5.0f;
}

static void	reverse_mode(t_data *data)
{
	data->player.color = LIME;
	data->special_mode = REVERSE;
	data->player.size = 25;
	data->player.speed = 5.0f;
}

static void	normal_mode(t_data *data)
{
	data->player.color = MAROON;
	data->special_mode = NORMAL;
	data->player.size = 25;
	data->player.speed = 5.0f;
}

void	special_modes(t_data *data)
{
	int rnd;

	if (data->current_run % 10 == 0 && data->last_modeswap != data->current_run)
	{
		rnd = GetRandomValue(0, 8);
		while (data->special_mode == rnd)
			rnd = GetRandomValue(0, 8);
		if (rnd == 0)
			normal_mode(data);
		if (rnd == 1)
			reverse_mode(data);
		if (rnd == 2)
			big_mode(data);
		if (rnd == 3)
			ice_mode(data);
		if (rnd == 4)
			mirror_ice_mode(data);
		if (rnd == 5)
			growth_mode(data);
		if (rnd == 6)
			speed_mode(data);
		if (rnd == 7)
			slow_mode(data);
		if (rnd == 8)
			warp_mode(data);
		data->last_modeswap = data->current_run;
	}
	return ;
}