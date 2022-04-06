/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadingScreen.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:13:18 by khirsig           #+#    #+#             */
/*   Updated: 2022/03/31 11:57:34 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circlegame.hpp"

void	loadingScreen(Data &data)
{
	setCurrentTime(data);
	BeginDrawing();
	data.window.ClearBackground(RAYWHITE);
	drawPlayer(data);
	movePlayer(data);
	modeGUI(data);
	timeGUI(data);
	powerUpGUI(data);
	if (currentTime - startTime == 0)
		DrawText("3...", screenWidth / 2 - MeasureText("3...", menuTextSize[1]) / 2, screenHeight / 3, menuTextSize[1], data.player.getColor());
	if (currentTime - startTime == 1)
		DrawText("2...", screenWidth / 2 - MeasureText("2...", menuTextSize[1]) / 2, screenHeight / 3, menuTextSize[1], data.player.getColor());
	if (currentTime - startTime == 2)
		DrawText("1...", screenWidth / 2 - MeasureText("1...", menuTextSize[1]) / 2, screenHeight / 3, menuTextSize[1], data.player.getColor());
	EndDrawing();
	if (currentTime - startTime == 3)
	{
		data.gameMode = IN_GAME;
		for (int i = 0; i < data.circleAmount; ++i)
		{
			data.circle[i].activateCircle();
			data.circle[i].resetCircle();
		}
		setStartTime(data);
		setCurrentTime(data);
		data.circle->setMinSpeed(2.0);
        data.circle->setMaxSpeed(5.0);
		for (int i = 0; i < data.powerUpAmount; ++i)
   		{
    		data.powerUp[i].setState(DISABLED);
			data.powerUp[i].setNextSpawnTime(currentTime + GetRandomValue(5, 20));
    		data.modeTime = currentTime;
		}
	}
}
