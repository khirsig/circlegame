/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textGUI.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:11:59 by khirsig           #+#    #+#             */
/*   Updated: 2022/03/30 13:44:35 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circlegame.hpp"

#define MODE_STR modeText[data.player.getMode()].c_str()

void	modeGUI(Data &data)
{
	int	modeSize = screenHeight / 36;

	DrawText(MODE_STR, screenWidth / 2 - MeasureText(MODE_STR, modeSize) / 2, modeSize / 2, modeSize, data.player.getColor());
	if ((data.currentTime - data.startTime) % 10 == 7 && !data.gameover)
		DrawText("Changing MODE in 3...", screenWidth / 2 - MeasureText("Changing MODE in 3...", modeSize) / 2, modeSize * 2, modeSize, data.player.getColor());
	if ((data.currentTime - data.startTime) % 10 == 8 && !data.gameover)
		DrawText("Changing MODE in 2...", screenWidth / 2 - MeasureText("Changing MODE in 2...", modeSize) / 2, modeSize * 2, modeSize, data.player.getColor());
	if ((data.currentTime - data.startTime) % 10 == 9 && !data.gameover)
		DrawText("Changing MODE in 1...", screenWidth / 2 - MeasureText("Changing MODE in 1...", modeSize) / 2, modeSize * 2, modeSize, data.player.getColor());

}

void	timeGUI(Data &data)
{
	int	timeSize = screenHeight / 30;
	std::string timeText;
	if (data.gameMode == IN_GAME)
		timeText = "Score: " + std::to_string(data.currentTime - data.startTime);
	else
		timeText = "Score: 0";
	int	timeLen = MeasureText(timeText.c_str(), timeSize);
	Color timeCol = (Color){ 0, 121, 241, 255 };

	DrawText(timeText.c_str(), timeSize, screenHeight - timeSize * 1.5, timeSize, timeCol);
}

void	powerUpGUI(Data &data)
{
	int	powerUpSize = screenHeight / 30;
	int	powerUpID = data.player.getPowerUpHold();

	DrawCircle(powerUpSize * 1.5, powerUpSize * 1.5, powerUpSize, data.player.getPlayerColor());
	DrawCircle(powerUpSize * 1.5, powerUpSize * 1.5, powerUpSize * 0.8, WHITE);
	if (powerUpID != -1)
	{
		switch (powerUpID) {
			case SKIPMODE :
				DrawText("SM", powerUpSize * 1.2, powerUpSize * 1.2, powerUpSize / 2, DARKGRAY);
				break ;
			case SHIELD :
				DrawText("SH", powerUpSize * 1.2, powerUpSize * 1.2, powerUpSize / 2, DARKGRAY);
				break ;
		}

	}
}
