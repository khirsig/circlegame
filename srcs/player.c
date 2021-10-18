/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:27:41 by khirsig           #+#    #+#             */
/*   Updated: 2021/10/18 14:35:26 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/circlegame.h"

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
	DrawCircleV(data->player.position, data->player.size, data->player.color);
	return ;
}