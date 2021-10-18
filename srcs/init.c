/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:10:28 by khirsig           #+#    #+#             */
/*   Updated: 2021/10/17 12:08:54 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minigame.h"

int	init_data(t_data *data)
{
	data->screen_width = 800;
	data->screen_height = 600;
	data->ball_position.x = (float)data->screen_width/2;
	data->ball_position.y = (float)data->screen_height/2;
	data->ball_color = MAROON;
	data->ball_size = 25;
	data->enemy_speed = 3.0f;
	data->seconds_run = 0;
	data->last_modeswap = 0;
	data->special_mode = 0;
	data->current_enemies = 0;
	data->total_enemies = 0;
	data->slide_amount = 0;
	data->is_sliding = FALSE;
	data->hiscore = LoadStorageValue(STORAGE_POSITION_HISCORE);
	return (0);
}