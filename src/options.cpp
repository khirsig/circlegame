/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 09:42:50 by khirsig           #+#    #+#             */
/*   Updated: 2022/04/29 17:13:42 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circlegame.hpp"

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

void	optionsScreen(Data &data)
{
	cursorOnButton(data, data.interface.resButton[0], screenWidth / 5 * 0.7, screenHeight / 5, screenWidth / 16, screenHeight / 24);
	cursorOnButton(data, data.interface.resButton[1], screenWidth / 5 * 1.1, screenHeight / 5, screenWidth / 16, screenHeight / 24);

	if (data.interface.resButton[0])
		changeWidth(data);


	BeginDrawing();
	ClearBackground(RAYWHITE);
	if (drawMenuText(optionsText[0].c_str(), screenWidth / 2 - MeasureText(optionsText[0].c_str(), menuTextSize[1]) / 2, screenHeight / 8 * 7, menuTextSize[1]))
	{
		if (data.interface.onButton != nullptr)
			*data.interface.onButton = false;
		data.gameMode = START_SCREEN;
	}

	raylib::Color col;
	DrawRectangle(screenWidth / 5 * 0.7, screenHeight / 5, screenWidth / 16, screenHeight / 24, LIGHTGRAY);
	if (data.interface.resButton[0])
		col = RED;
	else
		col = BLACK;
	DrawText(data.interface.widthStr.c_str(), screenWidth / 5 * 0.7 + MeasureText(data.interface.widthStr.c_str(), menuTextSize[2]) / 2, screenHeight / 5 + screenHeight / 48 - menuTextSize[2] / 2, menuTextSize[2], col);

	DrawRectangle(screenWidth / 5 * 1.1, screenHeight / 5, screenWidth / 16, screenHeight / 24, LIGHTGRAY);
	if (data.interface.resButton[1])
		col = RED;
	else
		col = BLACK;
		DrawText(data.interface.heightStr.c_str(), screenWidth / 5 * 1.1 + MeasureText(data.interface.heightStr.c_str(), menuTextSize[2]) / 2, screenHeight / 5 + screenHeight / 48 - menuTextSize[2] / 2, menuTextSize[2], col);


	DrawText(optionsText[1].c_str(), screenWidth / 5 * 0.2, screenHeight / 5 + menuTextSize[2] * 0.5, menuTextSize[2], BLUE);

	EndDrawing();
}
