/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadingScreen.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:13:18 by khirsig           #+#    #+#             */
/*   Updated: 2022/06/14 14:37:49 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/circlegame.hpp"

void	loadingScreen(Data &data)
{
	setCurrentTime(data);
	BeginDrawing();
	data.window.ClearBackground(backgroundColor);
	drawPlayer(data);
	movePlayer(data);
	modeGUI(data);
	timeGUI(data);
	if (data.gameType == RANKEDGAME)
		eloGUI(data);
	powerUpGUI(data);
	if (currentTime - startTime == 0)
		DrawText("3...", screenWidth / 2 - MeasureText("3...", menuTextSize[1]) / 2, screenHeight / 3, menuTextSize[1], data.player[0].getColor());
	if (currentTime - startTime == 1)
		DrawText("2...", screenWidth / 2 - MeasureText("2...", menuTextSize[1]) / 2, screenHeight / 3, menuTextSize[1], data.player[0].getColor());
	if (currentTime - startTime == 2)
		DrawText("1...", screenWidth / 2 - MeasureText("1...", menuTextSize[1]) / 2, screenHeight / 3, menuTextSize[1], data.player[0].getColor());
	EndDrawing();
	if (currentTime - startTime == 3)
	{
		data.gameMode = IN_GAME;
		if (data.gameType != RANKEDGAME)
		{
			data.circle[0].setMinSpeed(eloSpeed[data.difficulty]);
			data.circle[0].setMaxSpeed(eloSpeed[data.difficulty] + 1.0f);
		}
		else
		{
			data.circle[0].setMinSpeed(eloSpeed[data.user.elo.rank]);
			data.circle[0].setMaxSpeed(eloSpeed[data.user.elo.rank] + 1.0f);
			data.cfgCircleAmount = data.circleAmount;
			data.circleAmount = 4;
			data.circle.clear();
			for (int i = 0; i < data.circleAmount; ++i)
			{
				Circle temp;
				data.circle.push_back(temp);
			}
		}
		for (int i = 0; i < data.circleAmount; ++i)
		{
			data.circle[i].activateCircle();
			data.circle[i].resetCircle();
		}
		setStartTime(data);
		setCurrentTime(data);
		for (int i = 0; i < data.powerUpAmount; ++i)
		{
			data.powerUp[i].setState(DISABLED);
			data.powerUp[i].setNextSpawnTime(currentTime + GetRandomValue(5, 20));
			data.modeTime = currentTime;
		}
	}
}
