/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangles.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:55:12 by khirsig           #+#    #+#             */
/*   Updated: 2021/11/02 11:23:32 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/circlegame.h"

static void	triangle_setup(t_data *data)
{
	int rnd;

	// rnd = GetRandomValue(1, 4);
	data->triangle.alive = TRUE;
	rnd = 1;
	if (rnd == 1)
	{
		data->triangle.v1.x = 0;
		rnd = GetRandomValue(90, data->screen_height - 90);
		data->triangle.v1.y = rnd;
		data->triangle.v2.x = data->triangle.v1.x - 45;
		data->triangle.v2.y = data->triangle.v1.y - 15;
		data->triangle.v3.x = data->triangle.v1.x - 45;
		data->triangle.v3.y = data->triangle.v1.y + 15;
		data->triangle.move_direction = RIGHT;
	}
	data->triangle.color = RED;
}

void	triangles(t_data *data)
{
	if (data->triangle.alive == FALSE)
		triangle_setup(data);
	if (data->triangle.times_moved <= 30)
	{
		if	(data->triangle.move_direction == RIGHT)
		{
			data->triangle.v1.x += data->triangle.speed;
			data->triangle.v2.x += data->triangle.speed;
			data->triangle.v3.x += data->triangle.speed;
		}
		data->triangle.times_moved++;
	}
	if (data->triangle.times_moved > 30)
	{
		if (data->triangle.move_direction == RIGHT)
		{
			if (data->triangle.v1.y > data->player.position.y)
			{
				// data->triangle.v1.y += 0.05f
			}
		}
	}
	DrawTriangle(data->triangle.v1, data->triangle.v2, data->triangle.v3, data->triangle.color);
}