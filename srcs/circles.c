/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 16:34:07 by khirsig           #+#    #+#             */
/*   Updated: 2021/10/22 10:34:05 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/circlegame.h"

static void	circle_color(t_data *data, int enemy_id)
{
	int rnd;

	rnd = GetRandomValue (1, 5);
	if (rnd == 1)
		data->circle[enemy_id].color = ENEMYGRAY1;
	if (rnd == 2)
		data->circle[enemy_id].color = ENEMYGRAY2;
	if (rnd == 3)
		data->circle[enemy_id].color = ENEMYGRAY3;
	if (rnd == 4)
		data->circle[enemy_id].color = ENEMYGRAY4;
	if (rnd == 5)
		data->circle[enemy_id].color = ENEMYGRAY5;
	return ;
}

static void	circle_setup(t_data *data, int enemy_id)
{
	int rnd;

	rnd = GetRandomValue(1, 4);
	data->circle[enemy_id].speed = GetRandomValue(2, 4);
	data->circle[enemy_id].size = GetRandomValue(20, 30);
	circle_color(data, enemy_id);
	if (rnd == 1)
	{
		data->circle[enemy_id].position.x = data->screen_width + data->circle[enemy_id].size;
		rnd = GetRandomValue(data->circle[enemy_id].size, data->screen_height + data->circle[enemy_id].size);
		data->circle[enemy_id].position.y = rnd;
		data->circle[enemy_id].move_direction = LEFT;
	}
	else if (rnd == 2)
	{
		rnd = GetRandomValue(data->circle[enemy_id].size, data->screen_width - data->circle[enemy_id].size);
		data->circle[enemy_id].position.x = rnd;
		data->circle[enemy_id].position.y = 0 - data->circle[enemy_id].size;
		data->circle[enemy_id].move_direction = DOWN;
	}
	else if (rnd == 3)
	{
		data->circle[enemy_id].position.x = 0 - data->circle[enemy_id].size;
		rnd = GetRandomValue(data->circle[enemy_id].size, data->screen_height - data->circle[enemy_id].size);
		data->circle[enemy_id].position.y = rnd;
		data->circle[enemy_id].move_direction = RIGHT;
	}
	else if (rnd == 4)
	{
		rnd = GetRandomValue(data->circle[enemy_id].size, data->screen_width - data->circle[enemy_id].size);
		data->circle[enemy_id].position.x = rnd;
		data->circle[enemy_id].position.y = data->screen_height + data->circle[enemy_id].size;
		data->circle[enemy_id].move_direction = UP;
	}
	data->current_circles++;
	data->total_circles++;
}

void	circles(t_data *data)
{
	int max_enemies;
	int index;

	if (data->seconds_run < 5)
		max_enemies = 1;
	else if (data->seconds_run < 25)
		max_enemies = data->seconds_run / 5 + 1;
	else
		max_enemies = 5;
	while (data->current_circles < max_enemies)
		circle_setup(data, data->current_circles);
	index = 0;
	while (index < data->current_circles)
	{
		DrawCircleV(data->circle[index].position, data->circle[index].size, data->circle[index].color);
		if (data->circle[index].move_direction == UP)
		{
			data->circle[index].position.y -= data->circle[index].speed;
			if (data->circle[index].position.y <= 0 - data->circle[index].size)
			{
				data->current_circles--;
				circle_setup(data, index);
			}
		}
		else if (data->circle[index].move_direction == DOWN)
		{
			data->circle[index].position.y += data->circle[index].speed;
			if (data->circle[index].position.y >= data->screen_height + data->circle[index].size)
			{
				data->current_circles--;
				circle_setup(data, index);
			}
		}
		else if (data->circle[index].move_direction == RIGHT)
		{
			data->circle[index].position.x += data->circle[index].speed;
			if (data->circle[index].position.x >= data->screen_width + data->circle[index].size)
			{
				data->current_circles--;
				circle_setup(data, index);
			}
		}
		else if (data->circle[index].move_direction == LEFT)
		{
			data->circle[index].position.x -= data->circle[index].speed;
			if (data->circle[index].position.x <= 0 - data->circle[index].size)
			{
				data->current_circles--;
				circle_setup(data, index);
			}
		}
		index++;
	}
}
