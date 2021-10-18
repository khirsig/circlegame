/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slide.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:59:57 by khirsig           #+#    #+#             */
/*   Updated: 2021/10/18 09:53:53 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/circlegame.h"

void	ice_slide(t_data *data)
{
	char *temp;

	if (data->is_sliding == TRUE)
	{
		if ((data->slide_direction == RIGHT || data->slide_direction == RIGHT_DOWN || data->slide_direction == RIGHT_UP)
			&& data->ball_position.x != data->screen_width - data->ball_size)
			data->ball_position.x += 2.5f;
		if ((data->slide_direction == LEFT || data->slide_direction == LEFT_DOWN || data->slide_direction == LEFT_UP)
			&& data->ball_position.x != data->ball_size)
			data->ball_position.x -= 2.5f;
		if ((data->slide_direction == UP || data->slide_direction == LEFT_UP || data->slide_direction == RIGHT_UP)
			&& data->ball_position.y != data->ball_size)
			data->ball_position.y -= 2.5f;
		if ((data->slide_direction == DOWN || data->slide_direction == LEFT_DOWN || data->slide_direction == RIGHT_DOWN)
			&& data->ball_position.y != data->screen_height - data->ball_size)
			data->ball_position.y += 2.5f;
	}
	if ((IsKeyReleased(KEY_D) || IsKeyReleased(KEY_RIGHT)) && data->ball_position.x != data->screen_width - data->ball_size)
	{
		data->slide_direction = RIGHT;
		data->is_sliding = TRUE;
		data->slide_amount = 0;
	}
	if ((IsKeyReleased(KEY_A) || IsKeyReleased(KEY_LEFT)) && data->ball_position.x != data->ball_size)
	{
		data->slide_direction = LEFT;
		data->is_sliding = TRUE;
		data->slide_amount = 0;
	}
	if ((IsKeyReleased(KEY_W) || IsKeyReleased(KEY_UP)) && data->ball_position.y != data->ball_size)
	{
		if (data->slide_direction == RIGHT)
			data->slide_direction = RIGHT_UP;
		else if (data->slide_direction == LEFT)
			data->slide_direction = LEFT_UP;
		else
			data->slide_direction = UP;
		data->is_sliding = TRUE;
		data->slide_amount = 0;
	}
	if ((IsKeyReleased(KEY_S) || IsKeyReleased(KEY_DOWN)) && data->ball_position.y != data->screen_height - data->ball_size)
	{
		if (data->slide_direction == LEFT)
			data->slide_direction = LEFT_DOWN;
		else if (data->slide_direction == RIGHT)
			data->slide_direction = RIGHT_DOWN;
		else
			data->slide_direction = DOWN;
		data->is_sliding = TRUE;
		data->slide_amount = 0;
	}
	temp = ft_itoa(data->slide_amount);
	DrawText(temp, 10, 50, 20, SKYBLUE);
	free(temp);
	temp = ft_itoa(data->is_sliding);
	DrawText(temp, 10, 70, 20, SKYBLUE);
	free(temp);
	if (data->is_sliding == TRUE)
		data->slide_amount++;
}

void	mirror_slide(t_data *data)
{
	char *temp;

	if (data->is_sliding == TRUE)
	{
		if ((data->slide_direction == RIGHT || data->slide_direction == RIGHT_DOWN || data->slide_direction == RIGHT_UP)
			&& data->ball_position.x != data->screen_width - data->ball_size)
			data->ball_position.x -= 2.5f;
		if ((data->slide_direction == LEFT || data->slide_direction == LEFT_DOWN || data->slide_direction == LEFT_UP)
			&& data->ball_position.x != data->ball_size)
			data->ball_position.x += 2.5f;
		if ((data->slide_direction == UP || data->slide_direction == LEFT_UP || data->slide_direction == RIGHT_UP)
			&& data->ball_position.y != data->ball_size)
			data->ball_position.y += 2.5f;
		if ((data->slide_direction == DOWN || data->slide_direction == LEFT_DOWN || data->slide_direction == RIGHT_DOWN)
			&& data->ball_position.y != data->screen_height - data->ball_size)
			data->ball_position.y -= 2.5f;
	}
	if ((IsKeyReleased(KEY_D) || IsKeyReleased(KEY_RIGHT)) && data->ball_position.x != data->screen_width - data->ball_size)
	{
		data->slide_direction = LEFT;
		data->is_sliding = TRUE;
		data->slide_amount = 0;
	}
	if ((IsKeyReleased(KEY_A) || IsKeyReleased(KEY_LEFT)) && data->ball_position.x != data->ball_size)
	{
		data->slide_direction = RIGHT;
		data->is_sliding = TRUE;
		data->slide_amount = 0;
	}
	if ((IsKeyReleased(KEY_W) || IsKeyReleased(KEY_UP)) && data->ball_position.y != data->ball_size)
	{
		if (data->slide_direction == RIGHT)
			data->slide_direction = LEFT_DOWN;
		else if (data->slide_direction == LEFT)
			data->slide_direction = RIGHT_DOWN;
		else
			data->slide_direction = DOWN;
		data->is_sliding = TRUE;
		data->slide_amount = 0;
	}
	if ((IsKeyReleased(KEY_S) || IsKeyReleased(KEY_DOWN)) && data->ball_position.y != data->screen_height - data->ball_size)
	{
		if (data->slide_direction == LEFT)
			data->slide_direction = RIGHT_UP;
		else if (data->slide_direction == RIGHT)
			data->slide_direction = LEFT_UP;
		else
			data->slide_direction = UP;
		data->is_sliding = TRUE;
		data->slide_amount = 0;
	}
	temp = ft_itoa(data->slide_amount);
	DrawText(temp, 10, 50, 20, DARKGREEN);
	free(temp);
	temp = ft_itoa(data->is_sliding);
	DrawText(temp, 10, 70, 20, DARKGREEN);
	free(temp);
	if (data->is_sliding == TRUE)
		data->slide_amount++;
}
