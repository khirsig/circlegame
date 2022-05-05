/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ingame.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:17:26 by khirsig           #+#    #+#             */
/*   Updated: 2022/05/05 10:43:36 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circlegame.hpp"

void	ingame(Data &data)
{
	if (!gameover)
	{
		setCurrentTime(data);
		changeMode(data);
		for (int i = 0; i < data.playerAmount; ++i)
			data.player[i].modeExec();
		powerUpSpawn(data);
		takePowerUp(data);
		usePowerUp(data);
		increaseCircleSpeed(data);
		data.circle[0].updateSpeed();
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
	checkCircleCollision(data);
	if (!gameover)
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
	if (gameover)
	{
		if (data.gameType == RANKEDGAME)
		{
			DrawText(menuText[3].c_str(), screenWidth / 2 - MeasureText(menuText[3].c_str(), menuTextSize[3]) / 2, screenHeight / 4, menuTextSize[3], RED);
			DrawText(menuText[4].c_str(), screenWidth / 2 - MeasureText(menuText[4].c_str(), menuTextSize[4]) / 2, screenHeight / 3, menuTextSize[4], DARKGRAY);
		}
		else if (data.gameType == NORMALGAME)
		{
			DrawText(menuText[3].c_str(), screenWidth / 2 - MeasureText(menuText[3].c_str(), menuTextSize[3]) / 2, screenHeight / 4, menuTextSize[3], RED);
			DrawText(menuText[5].c_str(), screenWidth / 2 - MeasureText(menuText[5].c_str(), menuTextSize[4]) / 2, screenHeight / 3, menuTextSize[4], DARKGRAY);
		}
		else if (data.gameType == SPLITSCREEN)
		{
			if (data.dyingPlayer == 0)
				DrawText(menuText[6].c_str(), screenWidth / 2 - MeasureText(menuText[6].c_str(), menuTextSize[3]) / 2, screenHeight / 4, menuTextSize[3], data.player[1].getPlayerColor());
			else
				DrawText(menuText[7].c_str(), screenWidth / 2 - MeasureText(menuText[7].c_str(), menuTextSize[3]) / 2, screenHeight / 4, menuTextSize[3], data.player[0].getPlayerColor());
			DrawText(menuText[5].c_str(), screenWidth / 2 - MeasureText(menuText[5].c_str(), menuTextSize[4]) / 2, screenHeight / 3, menuTextSize[4], DARKGRAY);
		}
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
