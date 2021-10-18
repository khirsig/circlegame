/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:34:22 by khirsig           #+#    #+#             */
/*   Updated: 2021/10/18 14:37:28 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/circlegame.h"

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

	if (data->seconds_run % 10 == 0 && data->last_modeswap != data->seconds_run)
	{
		rnd = GetRandomValue(0, 6);
		while (data->special_mode == rnd)
			rnd = GetRandomValue(0, 6);
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
		data->last_modeswap = data->seconds_run;
	}
	return ;
}