/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   warp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:32:14 by khirsig           #+#    #+#             */
/*   Updated: 2021/11/10 00:03:41 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/circlegame.h"

static void	warp_get_dir(t_data *data)
{
	if (IsKeyReleased(KEY_A) || IsKeyReleased(KEY_LEFT))
		data->player.warp_direction = LEFT;
	if (IsKeyReleased(KEY_D) || IsKeyReleased(KEY_RIGHT))
		data->player.warp_direction = RIGHT;
	if (IsKeyReleased(KEY_S) || IsKeyReleased(KEY_DOWN))
		data->player.warp_direction = DOWN;
	if (IsKeyReleased(KEY_W) || IsKeyReleased(KEY_UP))
		data->player.warp_direction = UP;
}
void	warp_movement(t_data *data)
{
	warp_get_dir(data);
	if (data->player.warp_power >= 50)
	{
		data->player.warp_power = 0;
		if (data->player.warp_direction == LEFT)
			data->player.position.x -= 80;
		if (data->player.warp_direction == RIGHT)
			data->player.position.x += 80;
		if (data->player.warp_direction == UP)
			data->player.position.y -= 80;
		if (data->player.warp_direction == DOWN)
			data->player.position.y += 80;
	}
	else
		data->player.warp_power += 1;
	return ;
}
