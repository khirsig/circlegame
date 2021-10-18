/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 21:27:09 by khirsig           #+#    #+#             */
/*   Updated: 2021/10/17 10:42:38 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minigame.h"

void	enemy_collision(t_data *data)
{
	int index;
	int index2;

	index = 0;
	while (index < data->current_enemies)
	{
		index2 = 0;
		while (index2 < data->current_enemies)
		{
			if (CheckCollisionCircles(data->enemy[index].position, data->enemy[index].size, data->enemy[index2].position, data->enemy[index2].size)
				&& index != index2 && data->enemy[index].move_direction != data->enemy[index2].move_direction)
			{
				if (data->enemy[index].move_direction == LEFT || data->enemy[index].move_direction == UP)
					data->enemy[index].move_direction += 2;
				else if (data->enemy[index].move_direction == RIGHT || data->enemy[index].move_direction == DOWN)
					data->enemy[index].move_direction -= 2;
				if (data->enemy[index2].move_direction == LEFT || data->enemy[index2].move_direction == UP)
					data->enemy[index2].move_direction += 2;
				else if (data->enemy[index2].move_direction == RIGHT || data->enemy[index2].move_direction == DOWN)
					data->enemy[index2].move_direction -= 2;
			}
			index2++;
		}
		index++;
	}
	return ;
}

int	player_collision(t_data *data)
{
	int index;

	index = 0;
	while (index < data->current_enemies)
	{
		if (CheckCollisionCircles(data->ball_position, data->ball_size, data->enemy[index].position, data->enemy[index].size))
		{
			SaveStorageValue(STORAGE_POSITION_HISCORE, data->seconds_run);
			return (GAMEOVER);
		}
		index++;
	}
	return (GAME);
}
