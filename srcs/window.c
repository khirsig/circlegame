/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:22:47 by khirsig           #+#    #+#             */
/*   Updated: 2022/02/16 11:37:46 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/circlegame.h"

void	start_screen(t_data *data)
{
	BeginDrawing();
	ClearBackground(RAYWHITE);
	circles(data);
	DrawText("CIRCLEGAME", 230, 250, 50, BLUE);
	DrawText("Press Enter to Play the Game!", 235, 300, 20, DARKGRAY);
	DrawText("alpha v0.1", data->screen_width - 105, data->screen_height - 30, 20, DARKGRAY);
	EndDrawing();
	if (IsKeyPressed(KEY_ENTER))
	{
		init_data(data);
		data->game_state = GAME;
	}
}

void	ingame_screen(t_data *data)
{
	if (data->game_state != GAMEOVER)
		player_collision(data);
	if (data->game_state == GAME)
	{
		move_character(data);
		special_modes(data);
		BeginDrawing();
		ClearBackground(RAYWHITE);
		player(data);
		circles(data);
		// if (data.triangle.alive == TRUE || data.seconds_run % 30 == 0)
		// 	triangles(&data);
		text_gui(data);
		EndDrawing();
		// circle_collision(data);
	}
	else
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);
		player(data);
		circles(data);
		text_gui(data);
		DrawText("GAMEOVER!", 250, 250, 50, RED);
		DrawText("Press Enter to return to Main Menu", 220, 300, 20, DARKGRAY);
		EndDrawing();
		if (IsKeyPressed(KEY_ENTER))
		{
			init_data(data);
			data->game_state = START;
		}
	}
}
