/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slide.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:59:57 by khirsig           #+#    #+#             */
/*   Updated: 2021/11/09 23:13:16 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/circlegame.h"

void	ice_slide(t_data *data)
{
	char *temp;

	if (data->player.is_sliding == TRUE)
	{
		if ((data->player.slide_direction == RIGHT || data->player.slide_direction == RIGHT_DOWN || data->player.slide_direction == RIGHT_UP)
			&& data->player.position.x != data->screen_width - data->player.size)
			data->player.position.x += data->player.speed / 2;
		if ((data->player.slide_direction == LEFT || data->player.slide_direction == LEFT_DOWN || data->player.slide_direction == LEFT_UP)
			&& data->player.position.x != data->player.size)
			data->player.position.x -= data->player.speed / 2;
		if ((data->player.slide_direction == UP || data->player.slide_direction == LEFT_UP || data->player.slide_direction == RIGHT_UP)
			&& data->player.position.y != data->player.size)
			data->player.position.y -= data->player.speed / 2;
		if ((data->player.slide_direction == DOWN || data->player.slide_direction == LEFT_DOWN || data->player.slide_direction == RIGHT_DOWN)
			&& data->player.position.y != data->screen_height - data->player.size)
			data->player.position.y += data->player.speed / 2;
	}
	if ((IsKeyReleased(KEY_D) || IsKeyReleased(KEY_RIGHT)) && data->player.position.x != data->screen_width - data->player.size)
	{
		data->player.slide_direction = RIGHT;
		data->player.is_sliding = TRUE;
		data->player.slide_amount = 0;
	}
	if ((IsKeyReleased(KEY_A) || IsKeyReleased(KEY_LEFT)) && data->player.position.x != data->player.size)
	{
		data->player.slide_direction = LEFT;
		data->player.is_sliding = TRUE;
		data->player.slide_amount = 0;
	}
	if ((IsKeyReleased(KEY_W) || IsKeyReleased(KEY_UP)) && data->player.position.y != data->player.size)
	{
		if (data->player.slide_direction == RIGHT)
			data->player.slide_direction = RIGHT_UP;
		else if (data->player.slide_direction == LEFT)
			data->player.slide_direction = LEFT_UP;
		else
			data->player.slide_direction = UP;
		data->player.is_sliding = TRUE;
		data->player.slide_amount = 0;
	}
	if ((IsKeyReleased(KEY_S) || IsKeyReleased(KEY_DOWN)) && data->player.position.y != data->screen_height - data->player.size)
	{
		if (data->player.slide_direction == LEFT)
			data->player.slide_direction = LEFT_DOWN;
		else if (data->player.slide_direction == RIGHT)
			data->player.slide_direction = RIGHT_DOWN;
		else
			data->player.slide_direction = DOWN;
		data->player.is_sliding = TRUE;
		data->player.slide_amount = 0;
	}
	temp = ft_itoa(data->player.slide_amount);
	DrawText(temp, 10, 50, 20, SKYBLUE);
	free(temp);
	temp = ft_itoa(data->player.is_sliding);
	DrawText(temp, 10, 70, 20, SKYBLUE);
	free(temp);
	if (data->player.is_sliding == TRUE)
		data->player.slide_amount++;
}

void	mirror_slide(t_data *data)
{
	char *temp;

	if (data->player.is_sliding == TRUE)
	{
		if ((data->player.slide_direction == RIGHT || data->player.slide_direction == RIGHT_DOWN || data->player.slide_direction == RIGHT_UP)
			&& data->player.position.x != data->screen_width - data->player.size)
			data->player.position.x += data->player.speed / 2;
		if ((data->player.slide_direction == LEFT || data->player.slide_direction == LEFT_DOWN || data->player.slide_direction == LEFT_UP)
			&& data->player.position.x != data->player.size)
			data->player.position.x -= data->player.speed / 2;
		if ((data->player.slide_direction == UP || data->player.slide_direction == LEFT_UP || data->player.slide_direction == RIGHT_UP)
			&& data->player.position.y != data->player.size)
			data->player.position.y -= data->player.speed / 2;
		if ((data->player.slide_direction == DOWN || data->player.slide_direction == LEFT_DOWN || data->player.slide_direction == RIGHT_DOWN)
			&& data->player.position.y != data->screen_height - data->player.size)
			data->player.position.y += data->player.speed / 2;
	}
	if ((IsKeyReleased(KEY_D) || IsKeyReleased(KEY_RIGHT)) && data->player.position.x != data->screen_width - data->player.size)
	{
		data->player.slide_direction = LEFT;
		data->player.is_sliding = TRUE;
		data->player.slide_amount = 0;
	}
	if ((IsKeyReleased(KEY_A) || IsKeyReleased(KEY_LEFT)) && data->player.position.x != data->player.size)
	{
		data->player.slide_direction = RIGHT;
		data->player.is_sliding = TRUE;
		data->player.slide_amount = 0;
	}
	if ((IsKeyReleased(KEY_W) || IsKeyReleased(KEY_UP)) && data->player.position.y != data->player.size)
	{
		if (data->player.slide_direction == LEFT)
			data->player.slide_direction = LEFT_DOWN;
		else if (data->player.slide_direction == RIGHT)
			data->player.slide_direction = RIGHT_DOWN;
		else
			data->player.slide_direction = DOWN;
		data->player.is_sliding = TRUE;
		data->player.slide_amount = 0;
	}
	if ((IsKeyReleased(KEY_S) || IsKeyReleased(KEY_DOWN)) && data->player.position.y != data->screen_height - data->player.size)
	{
		if (data->player.slide_direction == RIGHT)
			data->player.slide_direction = RIGHT_UP;
		else if (data->player.slide_direction == LEFT)
			data->player.slide_direction = LEFT_UP;
		else
			data->player.slide_direction = UP;
		data->player.is_sliding = TRUE;
		data->player.slide_amount = 0;
	}
	temp = ft_itoa(data->player.slide_amount);
	DrawText(temp, 10, 50, 20, DARKGREEN);
	free(temp);
	temp = ft_itoa(data->player.is_sliding);
	DrawText(temp, 10, 70, 20, DARKGREEN);
	free(temp);
	if (data->player.is_sliding == TRUE)
		data->player.slide_amount++;
}
