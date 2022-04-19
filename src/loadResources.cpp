/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadResources.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:30:58 by khirsig           #+#    #+#             */
/*   Updated: 2022/04/19 17:15:49 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circlegame.hpp"

void	loadResources(Data &data)
{
	int	xStart = screenWidth / 10 * 1, xEnd = screenWidth / 10 * 9;
	int	yStart = screenHeight / 8 * 6, yEnd = screenHeight / 8 * 7;
	int	maxWidth = xEnd - xStart;
	int	actualWidth;
	int	currentMaxWidth;

	for (unsigned int loadingStep = 0; loadingStep < 100; ++loadingStep)
	{
		actualWidth = maxWidth / 100 * loadingStep;
		currentMaxWidth = maxWidth - actualWidth;
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
			case 25:
				for (unsigned int i = 0; i < 5; ++i)
				{
					std::string temp = "./resources/mode0";
					if (i < 10)
					{
						temp += "0";
						temp += std::to_string(i);
						temp += ".png";
					}
					else
					{
						temp += std::to_string(i);
						temp += ".png";
					}
					data.player[0].modeImg[0].push_back(raylib::Texture(temp));
				}
				break ;
			case 50:
				if (data.playerAmount > 1)
				{
					for (unsigned int i = 0; i < 5; ++i)
					{
						std::string temp = "./resources/mode1";
						if (i < 10)
						{
							temp += "0";
							temp += std::to_string(i);
							temp += ".png";
						}
						else
						{
							temp += std::to_string(i);
							temp += ".png";
						}
						data.player[1].modeImg[1].push_back(raylib::Texture(temp));
					}
				}
				break ;
		}
	}
	data.gameMode = START_SCREEN;
}
