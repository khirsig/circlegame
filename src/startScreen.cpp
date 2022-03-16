/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startScreen.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:13:18 by khirsig           #+#    #+#             */
/*   Updated: 2022/03/16 13:51:36 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circlegame.hpp"

void	startScreen(Data &data)
{
	BeginDrawing();
	data.window.ClearBackground(RAYWHITE);
	DrawText(menuText[0], 230, 250, 50, BLUE);
	DrawText(menuText[1], 235, 300, 20, DARKGRAY);
	DrawText(menuText[2], data->screenWidth -105, data->screenHeight - 30, 20, DARKGRAY);
	EndDrawing();
	if (IsKeyPressed(KEY_ENTER))
	{
		data.game_state = LOADING_SCREEN;
	}
}
