/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startScreen.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:13:18 by khirsig           #+#    #+#             */
/*   Updated: 2022/03/16 16:46:12 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circlegame.hpp"

void	startScreen(Data &data)
{
	BeginDrawing();
	data.window.ClearBackground(RAYWHITE);
	DrawText(menuText[0].c_str(), data.screenWidth / 2 - menuTextLen[0], data.screenHeight / 3, menuTextSize[0], BLUE);
	DrawText(menuText[1].c_str(), 235, 300, menuTextSize[1], DARKGRAY);
	DrawText(menuText[2].c_str(), data.screenWidth -105, data.screenHeight - 30, menuTextSize[2], DARKGRAY);
	EndDrawing();
	if (IsKeyPressed(KEY_ENTER))
	{
		data.gameMode = LOADING_SCREEN;
	}
}
