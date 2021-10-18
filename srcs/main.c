/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:14:24 by khirsig           #+#    #+#             */
/*   Updated: 2021/10/18 13:42:43 by khirsig          ###   ########.fr       */
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
		enemies(&data);
		DrawCircleV(data.ball_position, data.ball_size, data.ball_color);
		text_gui(&data);
		EndDrawing();
		enemy_collision(&data);
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
