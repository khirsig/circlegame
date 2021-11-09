/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:14:24 by khirsig           #+#    #+#             */
/*   Updated: 2021/10/22 10:53:43 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/circlegame.h"


int	main(void)
{
	t_data data;

	init_data(&data);
	InitWindow(data.screen_width, data.screen_height, "circlegame");
	SetTargetFPS(60);
	while (!WindowShouldClose())
	{
		move_character(&data);
		special_modes(&data);
		BeginDrawing();
		ClearBackground(RAYWHITE);
		player(&data);
		circles(&data);
		// if (data.triangle.alive == TRUE || data.seconds_run % 30 == 0)
		// 	triangles(&data);
		text_gui(&data);
		EndDrawing();
		circle_collision(&data);
		if (player_collision(&data) == GAMEOVER)
			break ;
	}
	while (!WindowShouldClose())
	{
		BeginDrawing();
		DrawText("GAMEOVER!", 250, 250, 50, RED);
		EndDrawing();
	}
	CloseWindow();
	return (0);
}
