/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textGUI.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:11:59 by khirsig           #+#    #+#             */
/*   Updated: 2022/06/06 20:50:17 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circlegame.hpp"

static void	modeGUIText(Data &data, int playerID, const char *modeText)
{
	int	modeSize = screenHeight / 36;
	int	offset;
	if (data.playerAmount == 1 && playerID == 0)
		offset = screenWidth / 2;
	else if (playerID == 1)
		offset = screenWidth / 4 * 3;
	else
		offset = screenWidth / 4;
	DrawText(modeText, offset - MeasureText(modeText, modeSize) / 2, modeSize / 2, modeSize, data.player[playerID].getPlayerColor());

	if ((currentTime - startTime) % 10 == 7 && !gameover)
		DrawText("Changing MODE in 3...", offset - MeasureText("Changing MODE in 3...", modeSize) / 2, modeSize * 2, modeSize, data.player[playerID].getPlayerColor());
	if ((currentTime - startTime) % 10 == 8 && !gameover)
		DrawText("Changing MODE in 2...", offset - MeasureText("Changing MODE in 2...", modeSize) / 2, modeSize * 2, modeSize, data.player[playerID].getPlayerColor());
	if ((currentTime - startTime) % 10 == 9 && !gameover)
		DrawText("Changing MODE in 1...", offset - MeasureText("Changing MODE in 1...", modeSize) / 2, modeSize * 2, modeSize, data.player[playerID].getPlayerColor());
}

void	modeGUI(Data &data)
{
	if (data.playerAmount == 1)
		modeGUIText(data, 0, modeText[data.player[0].getMode()].c_str());
	else
	{
		modeGUIText(data, 0, modeText[data.player[0].getMode()].c_str());
		modeGUIText(data, 1, modeText[data.player[1].getMode()].c_str());
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

void	eloGUI(Data &data)
{
	int	eloSize = screenHeight / 6.0;
	raylib::Vector2	pos(0, 0);
	float	scale;
	if (data.user.elo.rank <= 16)
	{
		scale = (float)eloSize / 4096;
		pos.x = screenWidth - scale * 4096;
	}
	else
	{
		scale = (float)eloSize / 300;
		pos.x = screenWidth - scale * 300;
	}

	pos.y = 0;

	DrawTextureEx(data.interface.eloImg[data.user.elo.rank], pos, 0, scale, WHITE);
}

static void powerUpGUIGraphics(Data &data, int playerID)
{
	int	powerUpSize = screenHeight / 30.0;
	raylib::Vector2	pos(0, 0);
	int	powerUpID = data.player[playerID].getPowerUpHold();

	float			scale = (float)powerUpSize * 1.5 / 2048;

	if (playerID == 0)
		pos.x = powerUpSize;
	else
		pos.x = screenWidth - powerUpSize - powerUpSize * 1.5 - scale * 2048;
	pos.y = powerUpSize;

	raylib::Vector2	offset(pos.x + scale * 1024, pos.y + scale * 1024);
	DrawTextureEx(data.interface.pubImg[playerID], pos, 0, scale, WHITE);

	if (powerUpID != -1)
	{
		switch (powerUpID) {
			case SKIPMODE :
				data.interface.powerupImg[powerUpID].Draw(offset, 0, scale * 0.5, WHITE);
				// DrawText("STD", offset.x, offset.y, powerUpSize / 2, DARKGRAY);
				break ;
			case SHIELD :
				data.interface.powerupImg[powerUpID].Draw(offset, 0, scale * 0.5, WHITE);
				break ;
			case IMPULSE :
				data.interface.powerupImg[powerUpID].Draw(offset, 0, scale * 0.5, WHITE);
				// DrawText("IMP", offset.x, offset.y, powerUpSize / 2, DARKGRAY);
				break ;
		}
	}
}

void	powerUpGUI(Data &data)
{
	powerUpGUIGraphics(data, 0);
	if (data.playerAmount > 1)
		powerUpGUIGraphics(data, 1);
}
