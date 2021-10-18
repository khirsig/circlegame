/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:10:28 by khirsig           #+#    #+#             */
/*   Updated: 2021/10/18 14:51:31 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/circlegame.h"

int	init_data(t_data *data)
{
	data->screen_width = 800;
	data->screen_height = 600;
	data->player.position.x = (float)data->screen_width/2;
	data->player.position.y = (float)data->screen_height/2;
	data->player.color = MAROON;
	data->player.size = 25;
	data->player.speed = 5.0f;
	data->player.growth_direction = UP;
	data->seconds_run = 0;
	data->last_modeswap = 0;
	data->special_mode = 0;
	data->current_circles = 0;
	data->total_circles = 0;
	data->player.slide_amount = 0;
	data->player.is_sliding = FALSE;
	data->hiscore = LoadStorageValue(STORAGE_POSITION_HISCORE);
	return (0);
}