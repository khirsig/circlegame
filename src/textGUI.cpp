/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textGUI.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:11:59 by khirsig           #+#    #+#             */
/*   Updated: 2022/04/07 16:53:08 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circlegame.hpp"

#define MODE_STR_P1 modeText[data.player[0].getMode()].c_str()
#define MODE_STR_P2 modeText[data.player[1].getMode()].c_str()

void	modeGUI(Data &data)
{
	int	modeSize = screenHeight / 36;
	int	playerOneOffset;
	if (data.playerAmount == 1)
		playerOneOffset = screenWidth / 2;
	else
		playerOneOffset = screenWidth / 4;
	DrawText(MODE_STR_P1, playerOneOffset - MeasureText(MODE_STR_P1, modeSize) / 2, modeSize / 2, modeSize, data.player[0].getColor());
	if ((currentTime - startTime) % 10 == 7 && !data.gameover)
		DrawText("Changing MODE in 3...", playerOneOffset - MeasureText("Changing MODE in 3...", modeSize) / 2, modeSize * 2, modeSize, data.player[0].getColor());
	if ((currentTime - startTime) % 10 == 8 && !data.gameover)
		DrawText("Changing MODE in 2...", playerOneOffset - MeasureText("Changing MODE in 2...", modeSize) / 2, modeSize * 2, modeSize, data.player[0].getColor());
	if ((currentTime - startTime) % 10 == 9 && !data.gameover)
		DrawText("Changing MODE in 1...", playerOneOffset - MeasureText("Changing MODE in 1...", modeSize) / 2, modeSize * 2, modeSize, data.player[0].getColor());
	if (data.playerAmount > 1)
	{
		DrawText(MODE_STR_P2, screenWidth / 4 * 3 - MeasureText(MODE_STR_P2, modeSize) / 2, modeSize / 2, modeSize, data.player[1].getColor());
		if ((currentTime - startTime) % 10 == 7 && !data.gameover)
			DrawText("Changing MODE in 3...", screenWidth / 4 * 3 - MeasureText("Changing MODE in 3...", modeSize) / 2, modeSize * 2, modeSize, data.player[1].getColor());
		if ((currentTime - startTime) % 10 == 8 && !data.gameover)
			DrawText("Changing MODE in 2...", screenWidth / 4 * 3 - MeasureText("Changing MODE in 2...", modeSize) / 2, modeSize * 2, modeSize, data.player[1].getColor());
		if ((currentTime - startTime) % 10 == 9 && !data.gameover)
			DrawText("Changing MODE in 1...", screenWidth / 4 * 3 - MeasureText("Changing MODE in 1...", modeSize) / 2, modeSize * 2, modeSize, data.player[1].getColor());
	}
}

void	timeGUI(Data &data)
{
	int	timeSize = screenHeight / 30;
	std::string timeText;
	if (data.gameMode == IN_GAME)
		timeText = "Score: " + std::to_string(currentTime - startTime);
	else
		timeText = "Score: 0";
	int	timeLen = MeasureText(timeText.c_str(), timeSize);
	Color timeCol = (Color){ 0, 121, 241, 255 };

	DrawText(timeText.c_str(), timeSize, screenHeight - timeSize * 1.5, timeSize, timeCol);
}

void	powerUpGUI(Data &data)
{
	int	powerUpSize = screenHeight / 30;
	int	powerUpID = data.player[0].getPowerUpHold();

	DrawCircle(powerUpSize * 1.5, powerUpSize * 1.5, powerUpSize, data.player[0].getPlayerColor());
	DrawCircle(powerUpSize * 1.5, powerUpSize * 1.5, powerUpSize * 0.8, WHITE);
	// DrawRectangle(powerUpSize * 1.5, powerUpSize * 1.5, powerUpSize, powerUpSize, data.player[0].getPlayerColor());
	float scale = (float)powerUpSize * 0.8 / 2048;
	raylib::Vector2 offset(powerUpSize * 0.8, powerUpSize * 0.8);
	if (powerUpID != -1)
	{
		switch (powerUpID) {
			case SKIPMODE :
				DrawText("SM", powerUpSize * 1.2, powerUpSize * 1.2, powerUpSize / 2, DARKGRAY);
				break ;
			case SHIELD :
				data.interface.powerupImg[0].Draw(offset, 0, scale, WHITE);
				break ;
			case RANDOMDIR :
				DrawText("RD", powerUpSize * 1.2, powerUpSize * 1.2, powerUpSize / 2, DARKGRAY);
				break ;
		}
	}
	if (data.playerAmount > 1)
	{
		int	powerUpID = data.player[1].getPowerUpHold();

		DrawCircle(SCREEN_WIDTH - powerUpSize * 1.5, powerUpSize * 1.5, powerUpSize, data.player[1].getPlayerColor());
		DrawCircle(SCREEN_WIDTH - powerUpSize * 1.5, powerUpSize * 1.5, powerUpSize * 0.8, WHITE);
		if (powerUpID != -1)
		{
			switch (powerUpID) {
				case SKIPMODE :
					DrawText("SM", SCREEN_WIDTH - powerUpSize * 1.2, powerUpSize * 1.2, powerUpSize / 2, DARKGRAY);
					break ;
				case SHIELD :
					DrawText("SH", SCREEN_WIDTH - powerUpSize * 1.2, powerUpSize * 1.2, powerUpSize / 2, DARKGRAY);
					break ;
				case RANDOMDIR :
					DrawText("RD", SCREEN_WIDTH - powerUpSize * 1.2, powerUpSize * 1.2, powerUpSize / 2, DARKGRAY);
					break ;

			}
		}
	}
}
