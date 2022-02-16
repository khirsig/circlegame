/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:14:24 by khirsig           #+#    #+#             */
/*   Updated: 2022/02/16 11:31:54 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/circlegame.h"

int	main(void)
{
	t_data data;

	data.screen_width = 800;
	data.screen_height = 600;
	data.seconds_run = 0;
	data.game_state = INIT;
	data.debug = FALSE;
	data.hiscore = LoadStorageValue(STORAGE_POSITION_HISCORE);
	InitWindow(data.screen_width, data.screen_height, "circlegame");
	SetTargetFPS(63);
	while (!WindowShouldClose())
	{
		debug_mode(&data);
		set_time(&data);
		if (data.game_state == INIT)
			init_data(&data);
		if (data.game_state == START)
			start_screen(&data);
		if (data.game_state == GAME || data.game_state == GAMEOVER)
			ingame_screen(&data);
	}
	CloseWindow();
	return (0);
}
