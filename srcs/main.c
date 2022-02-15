/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:14:24 by khirsig           #+#    #+#             */
/*   Updated: 2022/02/15 15:46:38 by khirsig          ###   ########.fr       */
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
	InitWindow(data.screen_width, data.screen_height, "circlegame");
	SetTargetFPS(60);
	while (!WindowShouldClose())
	{
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
