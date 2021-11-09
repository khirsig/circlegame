/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:27:41 by khirsig           #+#    #+#             */
/*   Updated: 2021/11/10 00:01:43 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/circlegame.h"

static void warp_direction_gui(t_data *data)
{
	Vector2 temp;

	temp.x = data->player.position.x;
	temp.y = data->player.position.y;
	if (data->player.warp_direction == UP)
	{
		temp.y -= 3;
		DrawCircleV(temp, data->player.size, GROWTH_PURPLE);
	}
	if (data->player.warp_direction == DOWN)
	{
		temp.y += 3;
		DrawCircleV(temp, data->player.size, GROWTH_PURPLE);
	}
	if (data->player.warp_direction == LEFT)
	{
		temp.x -= 3;
		DrawCircleV(temp, data->player.size, GROWTH_PURPLE);
	}
	if (data->player.warp_direction == RIGHT)
	{
		temp.x += 3;
		DrawCircleV(temp, data->player.size, GROWTH_PURPLE);
	}
	return ;
}

static void	warp_power_gui(t_data *data)
{
	int index;
	int	guidex;

	index = 0;
	guidex = 0;
	while (index < 50)
	{
		if (index < data->player.warp_power && index % 2 == 0)
			DrawText("|", data->player.position.x + guidex - 12, data->player.position.y - 5, 15, GROWTH_PURPLE);
		// else if (index % 2 == 0)
		// 	DrawText("|", data->player.position.x + guidex - 12, data->player.position.y - 5, 15, GRAY);
		index++;
		if (index % 2 == 0)
			guidex++;
	}
	return ;
}

static void growth_change(t_data *data)
{
	if (data->player.size >= data->player.growth_max)
		data->player.growth_direction = DOWN;
	if (data->player.size <= data->player.growth_min)
		data->player.growth_direction = UP;
	if (data->player.growth_direction == UP)
		data->player.size += 0.2f;
	if (data->player.growth_direction == DOWN)
		data->player.size -= 0.2f;
	return ;
}

void player(t_data *data)
{
	if (data->special_mode == GROWTH)
		growth_change(data);
	if (data->special_mode == WARP)
		warp_direction_gui(data);
	DrawCircleV(data->player.position, data->player.size, data->player.color);
	if (data->special_mode == WARP)
		warp_power_gui(data);
	return ;
}