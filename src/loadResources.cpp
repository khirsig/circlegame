/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadResources.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:30:58 by khirsig           #+#    #+#             */
/*   Updated: 2022/04/27 13:35:30 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circlegame.hpp"
// #include <json_struct.h>

std::string	getModePath(int i, int pNbr)
{
	std::string texLink = "./resources/mode";
	if (i < 10)
	{
		texLink += std::to_string(pNbr);
		texLink += "0";
		texLink += std::to_string(i);
		texLink += ".png";
	}
	else
	{
		texLink += std::to_string(pNbr);
		texLink += std::to_string(i);
		texLink += ".png";
	}
	return (texLink);
}

std::string	getPubPath(int i)
{
	std::string texLink = "./resources/pub";

	texLink += std::to_string(i);
	texLink += ".png";
	return (texLink);
}

std::string	getPowerUpPath(int i)
{
	std::string texLink = "./resources/powerup";

	if (i < 10)
	{
		texLink += "0";
		texLink += std::to_string(i);
		texLink += ".png";
	}
	else
	{
		texLink += std::to_string(i);
		texLink += ".png";
	}
	return (texLink);
}

std::string	getEloPath(int i)
{
	std::string texLink = "./resources/elo/elo";

	if (i < 10)
	{
		texLink += "0";
		texLink += std::to_string(i);
		texLink += ".png";
	}
	else
	{
		texLink += std::to_string(i);
		texLink += ".png";
	}
	return (texLink);
}

void	loadResources(Data &data)
{
	int		loginStep = 0;
	char	inputChar;
	int		inputKey;
	std::string inputString;
	while (loginStep < 2)
	{
		inputKey = GetKeyPressed();
		if ((inputChar = GetCharPressed()) && isalnum(inputChar) && inputString.length() < 12)
			inputString.push_back(inputChar);
		if (inputKey == KEY_BACKSPACE && inputString.length() > 0)
			inputString.pop_back();
		if (inputKey == KEY_ESCAPE)
			exit(EXIT_SUCCESS);
		if (inputKey == KEY_ENTER && inputString.length() >= 3)
		{
			if (loginStep == 0)
				data.user.username = inputString;
			if (loginStep == 1)
				data.user.password = inputString;
			inputString.clear();
			loginStep++;
		}

		BeginDrawing();
		data.window.ClearBackground(RAYWHITE);
		DrawRectangle(screenWidth / 3, screenHeight / 3 * 2, screenWidth / 3, screenHeight / 14, BLACK);
		DrawText(inputString.c_str(), screenWidth / 3 + screenHeight / 40, screenHeight / 3 * 2 + screenHeight / 36, menuTextSize[1], WHITE);
		switch (loginStep) {
			case 0 :
				DrawText("Please enter your name:", screenWidth / 2 - MeasureText("Please enter your name:", menuTextSize[1]) / 2, screenHeight / 2, menuTextSize[1], BLACK);
				break ;
			case 1 :
				DrawText("Please enter your password:", screenWidth / 2 - MeasureText("Please enter your password:", menuTextSize[1]) / 2, screenHeight / 2, menuTextSize[1], BLACK);
				break ;
		}
		EndDrawing();
	}
	loginServerRequest(data);

	unsigned int	loadingStep = 0, currentGraphic = 0;
	int				xStart = screenWidth / 10 * 1, xEnd = screenWidth / 10 * 9;
	int				yStart = screenHeight / 10 * 8, yEnd = screenHeight / 10 * 9;
	int				maxWidth = xEnd - xStart;
	int				actualWidth;

	while (loadingStep < 34)
	{
		actualWidth = maxWidth / 34 * loadingStep;
		if (actualWidth > maxWidth)
			actualWidth = maxWidth;

		BeginDrawing();
		data.window.ClearBackground(RAYWHITE);
		DrawRectangle(xStart, yStart, maxWidth, yEnd - yStart, GRAY);
		DrawRectangle(xStart, yStart, actualWidth, yEnd - yStart, RED);
		EndDrawing();

		if (loadingStep < 3)
		{
			data.interface.powerupImg.push_back(raylib::Texture(getPowerUpPath(currentGraphic)));
			currentGraphic++;
			if (loadingStep == 2)
				currentGraphic = 0;
		}
		else if (loadingStep >= 3 && loadingStep < 8)
		{
			data.player[0].modeImg.push_back(raylib::Texture(getModePath(currentGraphic, 0)));
			currentGraphic++;
			if (loadingStep == 7)
				currentGraphic = 0;
		}
		else if (loadingStep >= 8 && loadingStep < 13)
		{
			if (data.playerAmount > 1)
			{
				data.player[1].modeImg.push_back(raylib::Texture(getModePath(currentGraphic, 1)));
				currentGraphic++;
				if (loadingStep == 12)
					currentGraphic = 0;
			}
		}
		else if (loadingStep >= 13 && loadingStep < 15)
		{
			data.interface.pubImg.push_back(raylib::Texture(getPubPath(currentGraphic)));
			currentGraphic++;
			if (loadingStep == 14)
				currentGraphic = 0;
		}
		else if (loadingStep >= 15 && loadingStep < 34)
		{
			data.interface.eloImg.push_back(raylib::Texture(getEloPath(currentGraphic)));
			currentGraphic++;
			if (loadingStep == 33)
				currentGraphic = 0;
		}
		loadingStep++;
	}
	data.gameMode = START_SCREEN;
}
