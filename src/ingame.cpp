/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ingame.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:17:26 by khirsig           #+#    #+#             */
/*   Updated: 2022/04/28 09:12:20 by khirsig          ###   ########.fr       */
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
		if (IsKeyPressed(KEY_K) && (data.user.username == "tester" || data.gameType != RANKEDGAME))
		{
			data.player[0].setPowerUpHold(SHIELD);
			data.player[1].setPowerUpHold(SHIELD);
		}
		if (IsKeyPressed(KEY_P) && data.user.username == "tester" && data.gameType == RANKEDGAME)
			data.user.elo.rank = 10;
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
	if (data.gameType == RANKEDGAME)
		eloGUI(data);
	powerUpGUI(data);
	if (data.gameover)
	{
		DrawText(menuText[3].c_str(), screenWidth / 2 - MeasureText(menuText[3].c_str(), menuTextSize[3]) / 2, screenHeight / 4, menuTextSize[3], RED);
		DrawText(menuText[4].c_str(), screenWidth / 2 - MeasureText(menuText[4].c_str(), menuTextSize[4]) / 2, screenHeight / 3, menuTextSize[4], DARKGRAY);
		if (IsKeyPressed(KEY_ENTER))
		{
			if (data.gameType == RANKEDGAME)
			{
				calcElo(data);
				data.gameMode = ELO_SCREEN;
			}
			else
			{
				data.playerAmount = 1;
				data.gameType = NOGAME;
				newRound(data);
			}
		}
	}
	EndDrawing();
}
