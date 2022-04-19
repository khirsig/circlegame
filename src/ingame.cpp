/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ingame.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:17:26 by khirsig           #+#    #+#             */
/*   Updated: 2022/04/07 14:35:08 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circlegame.hpp"

void	ingame(Data &data)
{
	if (!data.gameover)
	{
		setCurrentTime(data);
		changeMode(data);
		for (int i = 0; i < data.playerAmount; ++i)
			data.player[i].modeExec();
		powerUpSpawn(data);
		takePowerUp(data);
		usePowerUp(data);
		increaseCircleSpeed(data);
		if (IsKeyPressed(KEY_K))
			data.player[0].setPowerUpHold(SHIELD);
		// 	data.player.setMode(3);
	}
	BeginDrawing();
	data.window.ClearBackground(RAYWHITE);
	drawCircle(data);
	if (!data.gameover)
	{
		powerUpDraw(data);
		movePlayer(data);
	}
	drawPlayer(data);
	modeGUI(data);
	timeGUI(data);
	powerUpGUI(data);
	if (data.gameover)
	{
		DrawText(menuText[3].c_str(), screenWidth / 2 - MeasureText(menuText[3].c_str(), menuTextSize[3]) / 2, screenHeight / 4, menuTextSize[3], RED);
		DrawText(menuText[4].c_str(), screenWidth / 2 - MeasureText(menuText[4].c_str(), menuTextSize[4]) / 2, screenHeight / 3, menuTextSize[4], DARKGRAY);
		if (IsKeyPressed(KEY_ENTER))
		{
			newRound(data);
		}
	}
	EndDrawing();
}