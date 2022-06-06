/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 09:42:50 by khirsig           #+#    #+#             */
/*   Updated: 2022/06/06 20:52:02 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circlegame.hpp"

static bool	drawReturn(Data &data, const char *text, int posX, int posY, int textSize)
{
	raylib::Color col;
	if (moveThroughMenuMouse(posX, posY, MeasureText(text, textSize), textSize))
		col = RED;
	else
		col = DARKGRAY;
	DrawText(text, posX, posY, textSize, col);
	if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE)) && col.r == 230)
		return (true);
	else
		return (false);
}

static void cursorOnButton(Data &data, bool &button, int x, int y, int width, int height)
{
	raylib::Vector2 cursor = GetMousePosition();

	if (cursor.x >= x && cursor.x <= x + width && cursor.y >= y && cursor.y <= y + height && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		if (button == true)
			button = false;
		else
		{
			if (data.interface.onButton != nullptr)
				*data.interface.onButton = false;
			data.interface.onButton = &button;
			button = true;
		}
	}
}

static void	changeWidth(Data &data)
{
	char		inputChar;
	int			inputKey;

	inputKey = GetKeyPressed();
	if ((inputChar = GetCharPressed()) && isnumber(inputChar) && data.interface.widthStr.length() < 4)
		data.interface.widthStr.push_back(inputChar);
	if (inputKey == KEY_BACKSPACE && data.interface.widthStr.length() > 0)
		data.interface.widthStr.pop_back();
	if (inputKey == KEY_ENTER && data.interface.widthStr.length() > 2)
	{
		int	newWidth = std::stoi(data.interface.widthStr);
		newWidth = newWidth / 16 * 16;
		int	newHeight = newWidth / 16 * 9;
		screenWidth = newWidth;
		screenHeight = newHeight;
		data.interface.widthStr = std::to_string(screenWidth);
		data.interface.heightStr = std::to_string(screenHeight);
		menuTextSize = { screenHeight / 8, screenHeight / 24, screenHeight / 36, screenHeight / 16, screenHeight / 28 };
		saveSettings(data);
		SetWindowSize(screenWidth, screenHeight);
	}
}

static void	changeHeight(Data &data)
{
	char		inputChar;
	int			inputKey;

	inputKey = GetKeyPressed();
	if ((inputChar = GetCharPressed()) && isnumber(inputChar) && data.interface.heightStr.length() < 4)
		data.interface.heightStr.push_back(inputChar);
	if (inputKey == KEY_BACKSPACE && data.interface.heightStr.length() > 0)
		data.interface.heightStr.pop_back();
	if (inputKey == KEY_ENTER && data.interface.heightStr.length() > 2)
	{
		int	newHeight = std::stoi(data.interface.heightStr);
		newHeight = newHeight / 9 * 9;
		int	newWidth = newHeight / 9 * 16;
		screenWidth = newWidth;
		screenHeight = newHeight;
		data.interface.widthStr = std::to_string(screenWidth);
		data.interface.heightStr = std::to_string(screenHeight);
		menuTextSize = { screenHeight / 8, screenHeight / 24, screenHeight / 36, screenHeight / 16, screenHeight / 28 };
		saveSettings(data);
		SetWindowSize(screenWidth, screenHeight);
	}
}

static void	drawDifficultyGUI(Data &data)
{
	raylib::Vector2 barPos;
	barPos.x = (float)screenWidth / 5 * 3.3;
	int	circRadius = (float)screenWidth / 150;
	barPos.y = (float)screenHeight / 5 + circRadius;
	int	barWidth = (float)screenWidth / 4;
	int	barHeight = (float)screenHeight / 100;

	DrawRectangle(barPos.x, barPos.y, barWidth, barHeight, DARKGRAY);
	data.interface.difCircPos.y = barPos.y + 6;
	raylib::Vector2 cursor = GetMousePosition();
	raylib::Color col;
	if (pow(cursor.x - data.interface.difCircPos.x, 2) + pow(cursor.y - data.interface.difCircPos.y, 2) < pow(12, 2) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && !data.interface.difButton)
	{
		if (data.interface.onButton != nullptr)
			*data.interface.onButton = false;
		data.interface.onButton = &data.interface.difButton;
		data.interface.difButton = true;
	}
	else if (data.interface.difButton && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		data.interface.difButton = false;
		saveSettings(data);
	}
	if (data.interface.difButton)
	{
		col = RED;
		if (cursor.x < barPos.x + barWidth && cursor.x > barPos.x)
			data.interface.difCircPos.x = cursor.x;
	}
	else
		col = BLACK;
	data.difficulty = (data.interface.difCircPos.x - barPos.x) / (barWidth / 19);
	if (data.difficulty > 18)
		data.difficulty = 18;
	DrawCircle(data.interface.difCircPos.x, data.interface.difCircPos.y, circRadius, col);
	DrawText(eloName[data.difficulty].c_str(), barPos.x + barWidth / 2 - MeasureText(eloName[data.difficulty].c_str(), menuTextSize[2]) / 2, barPos.y + barHeight * 3, menuTextSize[2], eloColor[data.difficulty]);
	DrawText(optionsText[2].c_str(), barPos.x - MeasureText(optionsText[2].c_str(), menuTextSize[2]) * 1.2, screenHeight / 5 + menuTextSize[2] * 0.5, menuTextSize[2], BLUE);

	int	eloSize = screenHeight / 9.0;
	raylib::Vector2	pos(0, 0);
	float	scale;
	if (data.difficulty <= 17)
	{
		scale = (float)eloSize / 4096;
		pos.x = screenWidth - scale * 4096 * 1.3;
		pos.y = barPos.y - scale * 2048;
	}
	else
	{
		scale = (float)eloSize / 300;
		pos.x = screenWidth - scale * 300 * 1.3;
		pos.y = barPos.y - scale * 150;
	}

	DrawTextureEx(data.interface.eloImg[data.difficulty], pos, 0, scale, WHITE);
}

static void	drawCircleAmountGUI(Data &data)
{
	raylib::Vector2 barPos;
	barPos.x = screenWidth / 5 * 3.3;
	barPos.y = screenHeight / 5 * 2 + menuTextSize[2] * 0.5;
	int	barWidth = screenWidth / 4;
	int	barHeight = screenHeight / 100;

	DrawRectangle(barPos.x, barPos.y, barWidth, barHeight, DARKGRAY);
	data.interface.circAmtCircPos.y = barPos.y + 6;
	raylib::Vector2 cursor = GetMousePosition();
	raylib::Color col;
	if (pow(cursor.x - data.interface.circAmtCircPos.x, 2) + pow(cursor.y - data.interface.circAmtCircPos.y, 2) < pow(12, 2) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && !data.interface.circAmtButton)
	{
		if (data.interface.onButton != nullptr)
			*data.interface.onButton = false;
		data.interface.onButton = &data.interface.circAmtButton;
		data.interface.circAmtButton = true;
	}
	else if (data.interface.circAmtButton && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		data.interface.circAmtButton = false;
		saveSettings(data);
	}
	if (data.interface.circAmtButton)
	{
		col = RED;
		if (cursor.x < barPos.x + barWidth && cursor.x > barPos.x)
			data.interface.circAmtCircPos.x = cursor.x;
	}
	else
		col = BLACK;
	data.circleAmount = (data.interface.circAmtCircPos.x - barPos.x) / (barWidth / 8) + 1;
	if (data.circleAmount > 8)
		data.circleAmount = 8;
	DrawCircle(data.interface.circAmtCircPos.x, data.interface.circAmtCircPos.y, screenWidth / 150, col);
	std::string	circAmtStr = std::to_string(data.circleAmount);
	if (data.circleAmount == 4)
		circAmtStr += " (Default)";
	DrawText(circAmtStr.c_str(), barPos.x + barWidth / 2 - MeasureText(circAmtStr.c_str(), menuTextSize[2]) / 2, barPos.y + barHeight * 3, menuTextSize[2], BLACK);
	DrawText(optionsText[3].c_str(), barPos.x - MeasureText(optionsText[3].c_str(), menuTextSize[2]) * 1.2, screenHeight / 5 * 2 + menuTextSize[2] * 0.5, menuTextSize[2], BLUE);
}


static void	drawResolutionGUI(Data &data)
{
	raylib::Color col;
	DrawRectangle(screenWidth / 5 * 0.7, screenHeight / 5, screenWidth / 16, screenHeight / 24, LIGHTGRAY);
	if (data.interface.resButton[0])
		col = RED;
	else
		col = BLACK;
	DrawText(data.interface.widthStr.c_str(), screenWidth / 5 * 0.7 + screenWidth / 32 - MeasureText(data.interface.widthStr.c_str(), menuTextSize[2]) / 2, screenHeight / 5 + screenHeight / 48 - menuTextSize[2] / 2, menuTextSize[2], col);

	DrawRectangle(screenWidth / 5 * 1.1, screenHeight / 5, screenWidth / 16, screenHeight / 24, LIGHTGRAY);
	if (data.interface.resButton[1])
		col = RED;
	else
		col = BLACK;
	DrawText(data.interface.heightStr.c_str(), screenWidth / 5 * 1.1 + screenWidth / 32 - MeasureText(data.interface.heightStr.c_str(), menuTextSize[2]) / 2, screenHeight / 5 + screenHeight / 48 - menuTextSize[2] / 2, menuTextSize[2], col);

}

void	optionsScreen(Data &data)
{
	cursorOnButton(data, data.interface.resButton[0], screenWidth / 5 * 0.7, screenHeight / 5, screenWidth / 16, screenHeight / 24);
	cursorOnButton(data, data.interface.resButton[1], screenWidth / 5 * 1.1, screenHeight / 5, screenWidth / 16, screenHeight / 24);

	if (data.interface.resButton[0])
		changeWidth(data);
	if (data.interface.resButton[1])
		changeHeight(data);

	BeginDrawing();
	ClearBackground(backgroundColor);

	if (drawReturn(data, optionsText[0].c_str(), screenWidth / 2 - MeasureText(optionsText[0].c_str(), menuTextSize[1]) / 2, screenHeight / 8 * 7, menuTextSize[1]))
	{
		if (data.interface.onButton != nullptr)
		{
			*data.interface.onButton = false;
			data.interface.onButton = nullptr;
		}
		data.gameMode = START_SCREEN;
	}

	drawResolutionGUI(data);
	drawDifficultyGUI(data);
	drawCircleAmountGUI(data);

	DrawText(optionsText[1].c_str(), screenWidth / 5 * 0.2, screenHeight / 5 + menuTextSize[2] * 0.5, menuTextSize[2], BLUE);

	EndDrawing();
}
