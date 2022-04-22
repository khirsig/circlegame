/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadResources.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:30:58 by khirsig           #+#    #+#             */
/*   Updated: 2022/04/22 10:43:53 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circlegame.hpp"
#include <thread>
#include <mutex>

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

void	loadResources(Data &data)
{
	unsigned int	loadingStep = 0, currentGraphic = 0;
	int				xStart = screenWidth / 10 * 1, xEnd = screenWidth / 10 * 9;
	int				yStart = screenHeight / 10 * 8, yEnd = screenHeight / 10 * 9;
	int				maxWidth = xEnd - xStart;
	int				actualWidth, maxGraphics;

	while (loadingStep < 11)
	{
		actualWidth = maxWidth / 11 * loadingStep;
		if (actualWidth > maxWidth)
			actualWidth = maxWidth;

		BeginDrawing();
		data.window.ClearBackground(RAYWHITE);
		DrawRectangle(xStart, yStart, maxWidth, yEnd - yStart, GRAY);
		DrawRectangle(xStart, yStart, actualWidth, yEnd - yStart, RED);
		EndDrawing();

		switch (loadingStep) {
			case 0:
				data.interface.powerupImg.push_back(raylib::Texture("./resources/powerup00.png"));
				break ;

			case 1:
				maxGraphics = 5;
				data.player[0].modeImg.push_back(raylib::Texture(getModePath(currentGraphic, 0)));
				break ;

			case 6:
				if (data.playerAmount > 1)
				{
					if (currentGraphic >= 5)
						currentGraphic = 0;
					maxGraphics = 5;
					data.player[1].modeImg.push_back(raylib::Texture(getModePath(currentGraphic, 1)));
				}
				break ;
		}
		loadingStep++;
	}
	data.gameMode = START_SCREEN;
}
