/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 09:42:50 by khirsig           #+#    #+#             */
/*   Updated: 2022/04/28 16:19:01 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circlegame.hpp"

void	optionsScreen(Data &data)
{
	BeginDrawing();
	ClearBackground(RAYWHITE);
	if (drawMenuText(optionsText[0].c_str(), screenWidth / 2 - MeasureText(optionsText[0].c_str(), menuTextSize[1]) / 2, screenHeight / 8 * 7, menuTextSize[1]))
		data.gameMode = START_SCREEN;

	DrawRectangle(screenWidth / 5 * 0.7, screenHeight / 5, screenWidth / 16, screenHeight / 24, LIGHTGRAY);
	DrawRectangle(screenWidth / 5 * 1.1, screenHeight / 5, screenWidth / 16, screenHeight / 24, LIGHTGRAY);
	DrawText(optionsText[1].c_str(), screenWidth / 5 * 0.2, screenHeight / 5 + menuTextSize[2] * 0.5, menuTextSize[2], BLUE);
	std::string str(std::to_string(screenHeight));
	DrawText(str.c_str(), screenWidth / 5 * 1.1, screenHeight / 5, menuTextSize[2], BLACK);
	str = std::to_string(screenWidth);
	DrawText(str.c_str(), screenWidth / 5 * 0.7, screenHeight / 5, menuTextSize[2], BLACK);
	EndDrawing();
}
