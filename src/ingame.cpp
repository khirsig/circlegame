/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ingame.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:17:26 by khirsig           #+#    #+#             */
/*   Updated: 2022/03/29 14:21:57 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circlegame.hpp"

void	ingame(Data &data)
{
	if (!data.gameover)
	{
		setCurrentTime(data);
		changeMode(data);
		data.player.modeExec();
	}
	BeginDrawing();
	data.window.ClearBackground(RAYWHITE);
	drawCircle(data);
	drawPlayer(data);
	if (!data.gameover)
		movePlayer(data);
	modeGUI(data);
	timeGUI(data);
	if (data.gameover)
	{
		DrawText(menuText[3].c_str(), screenWidth / 2 - MeasureText(menuText[3].c_str(), menuTextSize[3]) / 2, screenHeight / 4, menuTextSize[3], RED);
		DrawText(menuText[4].c_str(), screenWidth / 2 - MeasureText(menuText[4].c_str(), menuTextSize[4]) / 2, screenHeight / 3, menuTextSize[4], DARKGRAY);
		if (IsKeyPressed(KEY_ENTER))
		{
			newRound(data);
		}
	}
	EndDrawing();
}