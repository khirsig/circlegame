/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:06:02 by khirsig           #+#    #+#             */
/*   Updated: 2021/10/18 09:53:48 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/circlegame.h"

static void	reverse_movement(t_data *data)
{
	if ((IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) && data->ball_position.x != data->screen_width - data->ball_size)
	{
		if (data->is_sliding == TRUE)
		{
			data->is_sliding = FALSE;
			data->slide_direction = NONE;
		}
		data->ball_position.x += 5.0f;
	}
	if ((IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) && data->ball_position.x != data->ball_size)
	{
		if (data->is_sliding == TRUE)
		{
			data->is_sliding = FALSE;
			data->slide_direction = NONE;
		}
		data->ball_position.x -= 5.0f;
	}
	if ((IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) && data->ball_position.y != data->ball_size)
	{
		if (data->is_sliding == TRUE)
		{
			data->is_sliding = FALSE;
			data->slide_direction = NONE;
		}
		data->ball_position.y -= 5.0f;
	}
	if ((IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) && data->ball_position.y != data->screen_height - data->ball_size)
	{
		if (data->is_sliding == TRUE)
		{
			data->is_sliding = FALSE;
			data->slide_direction = NONE;
		}
		data->ball_position.y += 5.0f;
	}
}

static void	normal_movement(t_data *data)
{
	if ((IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) && data->ball_position.x != data->screen_width - data->ball_size)
	{
		if (data->is_sliding == TRUE)
		{
			data->slide_direction = NONE;
			data->is_sliding = FALSE;
		}
		data->ball_position.x += 5.0f;
	}
	if ((IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) && data->ball_position.x != data->ball_size)
	{
		if (data->is_sliding == TRUE)
		{
			data->is_sliding = FALSE;
			data->slide_direction = NONE;
		}
		data->ball_position.x -= 5.0f;
	}
	if ((IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) && data->ball_position.y != data->ball_size)
	{
		if (data->is_sliding == TRUE)
		{
			data->is_sliding = FALSE;
			data->slide_direction = NONE;
		}
		data->ball_position.y -= 5.0f;
	}
	if ((IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) && data->ball_position.y != data->screen_height - data->ball_size)
	{
		if (data->is_sliding == TRUE)
		{
			data->is_sliding = FALSE;
			data->slide_direction = NONE;
		}
		data->ball_position.y += 5.0f;
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
