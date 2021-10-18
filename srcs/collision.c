/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 21:27:09 by khirsig           #+#    #+#             */
/*   Updated: 2021/10/18 14:53:40 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/circlegame.h"

void	circle_collision(t_data *data)
{
	int index;
	int index2;

	index = 0;
	while (index < data->current_circles)
	{
		index2 = 0;
		while (index2 < data->current_circles)
		{
			if (CheckCollisionCircles(data->circle[index].position, data->circle[index].size, data->circle[index2].position, data->circle[index2].size)
				&& index != index2 && data->circle[index].move_direction != data->circle[index2].move_direction)
			{
				if (data->circle[index].move_direction == LEFT || data->circle[index].move_direction == UP)
					data->circle[index].move_direction += 2;
				else if (data->circle[index].move_direction == RIGHT || data->circle[index].move_direction == DOWN)
					data->circle[index].move_direction -= 2;
				if (data->circle[index2].move_direction == LEFT || data->circle[index2].move_direction == UP)
					data->circle[index2].move_direction += 2;
				else if (data->circle[index2].move_direction == RIGHT || data->circle[index2].move_direction == DOWN)
					data->circle[index2].move_direction -= 2;
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
	int temp;

	index = 0;
	while (index < data->current_circles)
	{
		if (CheckCollisionCircles(data->player.position, data->player.size, data->circle[index].position, data->circle[index].size))
		{
			temp = LoadStorageValue(STORAGE_POSITION_HISCORE);
			if (data->seconds_run > temp)
				SaveStorageValue(STORAGE_POSITION_HISCORE, data->seconds_run);
			return (GAMEOVER);
		}
		index++;
	}
	return (GAME);
}
