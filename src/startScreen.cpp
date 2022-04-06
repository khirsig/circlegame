/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startScreen.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:13:18 by khirsig           #+#    #+#             */
/*   Updated: 2022/04/06 13:50:17 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circlegame.hpp"

void	startScreen(Data &data)
{
	BeginDrawing();
	data.window.ClearBackground(RAYWHITE);
	drawCircle(data);
	DrawText(menuText[0].c_str(), screenWidth / 2 - MeasureText(menuText[0].c_str(), menuTextSize[0]) / 2, screenHeight / 4, menuTextSize[0], BLUE);
	DrawText(menuText[1].c_str(), screenWidth / 2 - MeasureText(menuText[1].c_str(), menuTextSize[1]) / 2, screenHeight / 3, menuTextSize[1], DARKGRAY);
	DrawText(menuText[2].c_str(), screenWidth - MeasureText(menuText[2].c_str(), menuTextSize[2]) * 1.2, screenHeight - menuTextSize[2] * 1.5, menuTextSize[2], DARKGRAY);
	EndDrawing();
	if (IsKeyPressed(KEY_ENTER))
	{
		data.gameMode = LOADING_SCREEN;
		setStartTime(data);
		setCurrentTime(data);
		for (int i = 0; i < data.circleAmount; ++i)
		{
			data.circle[i].activateCircle();
			data.circle[i].resetCircle();
		}
		for (int i = 0; i < data.playerAmount; ++i)
			data.player[i].setupPlayer();
	}
}
