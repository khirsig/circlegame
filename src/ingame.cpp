/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ingame.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:17:26 by khirsig           #+#    #+#             */
/*   Updated: 2022/03/23 12:20:04 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circlegame.hpp"

void	ingame(Data &data)
{
	BeginDrawing();
	data.window.ClearBackground(RAYWHITE);
	drawCircle(data);
	drawPlayer(data);
	modeGUI(data);
	if (data.gameover)
	{
		DrawText(menuText[3].c_str(), data.screenWidth / 2 - MeasureText(menuText[3].c_str(), menuTextSize[3]) / 2, data.screenHeight / 4, menuTextSize[3], RED);
		DrawText(menuText[4].c_str(), data.screenWidth / 2 - MeasureText(menuText[4].c_str(), menuTextSize[4]) / 2, data.screenHeight / 3, menuTextSize[4], DARKGRAY);
		if (IsKeyPressed(KEY_ENTER))
		{
			for (int i = 0; i < data.circleAmount; ++i)
			{
				data.circle[i].activateCircle();
				data.circle[i].resetCircle(data.screenWidth, data.screenHeight);
			}
			data.player.setupPlayer(data.screenWidth, data.screenHeight);
			data.gameMode = START_SCREEN;
			data.gameover = 0;
		}
	}
	EndDrawing();
}