/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 16:34:07 by khirsig           #+#    #+#             */
/*   Updated: 2021/10/17 09:45:06 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minigame.h"

static void	enemy_setup(t_data *data, int enemy_id)
{
	int rnd;

	rnd = GetRandomValue(1, 4);
	if (rnd == 1)
	{
		data->enemy[enemy_id].size = GetRandomValue(20, 40);
		data->enemy[enemy_id].position.x = data->screen_width + data->enemy[enemy_id].size;
		rnd = GetRandomValue(data->enemy[enemy_id].size, data->screen_height + data->enemy[enemy_id].size);
		data->enemy[enemy_id].position.y = rnd;
		data->enemy[enemy_id].move_direction = LEFT;
	}
	else if (rnd == 2)
	{
		data->enemy[enemy_id].size = GetRandomValue(20, 40);
		rnd = GetRandomValue(data->enemy[enemy_id].size, data->screen_width - data->enemy[enemy_id].size);
		data->enemy[enemy_id].position.x = rnd;
		data->enemy[enemy_id].position.y = 0 - data->enemy[enemy_id].size;
		data->enemy[enemy_id].move_direction = DOWN;
	}
	else if (rnd == 3)
	{
		data->enemy[enemy_id].size = GetRandomValue(20, 40);
		data->enemy[enemy_id].position.x = 0 - data->enemy[enemy_id].size;
		rnd = GetRandomValue(data->enemy[enemy_id].size, data->screen_height - data->enemy[enemy_id].size);
		data->enemy[enemy_id].position.y = rnd;
		data->enemy[enemy_id].move_direction = RIGHT;
	}
	else if (rnd == 4)
	{
		data->enemy[enemy_id].size = GetRandomValue(20, 40);
		rnd = GetRandomValue(data->enemy[enemy_id].size, data->screen_width - data->enemy[enemy_id].size);
		data->enemy[enemy_id].position.x = rnd;
		data->enemy[enemy_id].position.y = data->screen_height + data->enemy[enemy_id].size;
		data->enemy[enemy_id].move_direction = UP;
	}
	data->current_enemies++;
	data->total_enemies++;
}

void	enemies(t_data *data)
{
	int max_enemies;
	int index;

	if (data->seconds_run < 5)
		max_enemies = 1;
	else if (data->seconds_run < 50)
		max_enemies = data->total_enemies / 5 + 1;
	else
		max_enemies = 10;
	while (data->current_enemies < max_enemies)
		enemy_setup(data, data->current_enemies);
	index = 0;
	while (index < data->current_enemies)
	{
		DrawCircleV(data->enemy[index].position, data->enemy[index].size, DARKGRAY);
		if (data->enemy[index].move_direction == UP)
		{
			data->enemy[index].position.y -= data->enemy_speed;
			if (data->enemy[index].position.y <= 0 - data->enemy[index].size)
			{
				data->current_enemies--;
				enemy_setup(data, index);
			}
		}
		else if (data->enemy[index].move_direction == DOWN)
		{
			data->enemy[index].position.y += data->enemy_speed;
			if (data->enemy[index].position.y >= data->screen_height + data->enemy[index].size)
			{
				data->current_enemies--;
				enemy_setup(data, index);
			}
		}
		else if (data->enemy[index].move_direction == RIGHT)
		{
			data->enemy[index].position.x += data->enemy_speed;
			if (data->enemy[index].position.x >= data->screen_width + data->enemy[index].size)
			{
				data->current_enemies--;
				enemy_setup(data, index);
			}
		}
		else if (data->enemy[index].move_direction == LEFT)
		{
			data->enemy[index].position.x -= data->enemy_speed;
			if (data->enemy[index].position.x <= 0 - data->enemy[index].size)
			{
				data->current_enemies--;
				enemy_setup(data, index);
			}
		}
		index++;
	}
}
