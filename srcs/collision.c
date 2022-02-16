/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 21:27:09 by khirsig           #+#    #+#             */
/*   Updated: 2022/02/16 11:35:26 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/circlegame.h"

void	player_collision(t_data *data)
{
	int index;
	int temp;

	index = 0;
	while (index < data->current_circles)
	{
		if (CheckCollisionCircles(data->player.position, data->player.size, data->circle[index].position, data->circle[index].size))
		{
			temp = LoadStorageValue(STORAGE_POSITION_HISCORE);
			if (data->current_run > temp)
				SaveStorageValue(STORAGE_POSITION_HISCORE, data->current_run);
			data->hiscore = LoadStorageValue(STORAGE_POSITION_HISCORE);
			data->game_state = GAMEOVER;
		}
		index++;
	}
}
