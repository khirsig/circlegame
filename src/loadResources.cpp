/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadResources.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:30:58 by khirsig           #+#    #+#             */
/*   Updated: 2022/05/23 13:43:33 by khirsig          ###   ########.fr       */
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
		data.window.ClearBackground(backgroundColor);
		DrawRectangle(xStart, yStart, maxWidth, yEnd - yStart, GRAY);
		DrawRectangle(xStart, yStart, actualWidth, yEnd - yStart, RED);

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
			data.player[1].modeImg.push_back(raylib::Texture(getModePath(currentGraphic, 1)));
			currentGraphic++;
			if (loadingStep == 12)
				currentGraphic = 0;
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
		EndDrawing();

		loadingStep++;
	}
	data.gameMode = START_SCREEN;
}
