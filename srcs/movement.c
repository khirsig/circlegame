/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:06:02 by khirsig           #+#    #+#             */
/*   Updated: 2021/10/18 14:18:44 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/circlegame.h"

static void	reverse_movement(t_data *data)
{
	if ((IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) && data->player.position.x != data->screen_width - data->player.size)
	{
		if (data->player.is_sliding == TRUE)
		{
			data->player.is_sliding = FALSE;
			data->player.slide_direction = NONE;
		}
		data->player.position.x += data->player.speed;
	}
	if ((IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) && data->player.position.x != data->player.size)
	{
		if (data->player.is_sliding == TRUE)
		{
			data->player.is_sliding = FALSE;
			data->player.slide_direction = NONE;
		}
		data->player.position.x -= data->player.speed;
	}
	if ((IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) && data->player.position.y != data->player.size)
	{
		if (data->player.is_sliding == TRUE)
		{
			data->player.is_sliding = FALSE;
			data->player.slide_direction = NONE;
		}
		data->player.position.y -= data->player.speed;
	}
	if ((IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) && data->player.position.y != data->screen_height - data->player.size)
	{
		if (data->player.is_sliding == TRUE)
		{
			data->player.is_sliding = FALSE;
			data->player.slide_direction = NONE;
		}
		data->player.position.y += data->player.speed;
	}
}

static void	normal_movement(t_data *data)
{
	if ((IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) && data->player.position.x != data->screen_width - data->player.size)
	{
		if (data->player.is_sliding == TRUE)
		{
			data->player.slide_direction = NONE;
			data->player.is_sliding = FALSE;
		}
		data->player.position.x += data->player.speed;
	}
	if ((IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) && data->player.position.x != data->player.size)
	{
		if (data->player.is_sliding == TRUE)
		{
			data->player.is_sliding = FALSE;
			data->player.slide_direction = NONE;
		}
		data->player.position.x -= data->player.speed;
	}
	if ((IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) && data->player.position.y != data->player.size)
	{
		if (data->player.is_sliding == TRUE)
		{
			data->player.is_sliding = FALSE;
			data->player.slide_direction = NONE;
		}
		data->player.position.y -= data->player.speed;
	}
	if ((IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) && data->player.position.y != data->screen_height - data->player.size)
	{
		if (data->player.is_sliding == TRUE)
		{
			data->player.is_sliding = FALSE;
			data->player.slide_direction = NONE;
		}
		data->player.position.y += data->player.speed;
	}
}

void	move_character(t_data *data)
{
	if (data->special_mode != REVERSE && data->special_mode != MIRROR_ICE)
		normal_movement(data);
	else
		reverse_movement(data);
	if (data->special_mode == ICE)
		ice_slide(data);
	if (data->special_mode == MIRROR_ICE)
		mirror_slide(data);
	return ;
}
