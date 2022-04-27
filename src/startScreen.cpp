/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startScreen.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:13:18 by khirsig           #+#    #+#             */
/*   Updated: 2022/04/27 19:53:13 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circlegame.hpp"

static raylib::Color	getMenuTextColor(int x, int y, int width, int height)
{
	raylib::Color ret;
	raylib::Vector2 cursor = GetMousePosition();
	if (cursor.x >= x && cursor.x <= x + width && cursor.y >= y && cursor.y <= y + height)
	{
		ret = RED;
	}
	else
	{
		ret = DARKGRAY;
	}
	return (ret);
}

bool	drawMenuText(const char *text, int posX, int posY, int textSize, int id)
{
	raylib::Color col(getMenuTextColor(posX, posY, MeasureText(text, textSize), textSize));
	DrawText(text, posX, posY, textSize, col);
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && col.r == 230)
		return (true);
	else
		return (false);
}

void	startScreen(Data &data)
{
	BeginDrawing();
	data.window.ClearBackground(RAYWHITE);
	drawCircle(data);
	DrawText(menuText[0].c_str(), screenWidth / 2 - MeasureText(menuText[0].c_str(), menuTextSize[0]) / 2, screenHeight / 8, menuTextSize[0], BLUE);
	if (drawMenuText(mainMenuText[0].c_str(), screenWidth / 2 - MeasureText(mainMenuText[0].c_str(), menuTextSize[1]) / 2, screenHeight / 8 * 3, menuTextSize[1], 0))
		data.gameType = NORMALGAME;
	if (drawMenuText(mainMenuText[1].c_str(), screenWidth / 2 - MeasureText(mainMenuText[1].c_str(), menuTextSize[1]) / 2, screenHeight / 8 * 4, menuTextSize[1], 1))
		data.gameType = RANKEDGAME;
	if (drawMenuText(mainMenuText[2].c_str(), screenWidth / 2 - MeasureText(mainMenuText[2].c_str(), menuTextSize[1]) / 2, screenHeight / 8 * 5, menuTextSize[1], 2))
		data.gameType = SPLITSCREEN;
	if (drawMenuText(mainMenuText[3].c_str(), screenWidth / 2 - MeasureText(mainMenuText[3].c_str(), menuTextSize[1]) / 2, screenHeight / 8 * 6, menuTextSize[1], 3))
		exit(EXIT_SUCCESS);
	EndDrawing();


	if (data.gameType != NOGAME)
	{
		if (data.gameType == RANKEDGAME && !data.user.loggedIn)
			loginHandler(data);
		data.gameMode = LOADING_SCREEN;
		setStartTime(data);
		setCurrentTime(data);
		for (int i = 0; i < data.circleAmount; ++i)
		{
			data.circle[i].activateCircle();
			data.circle[i].resetCircle();
		}
		data.player[0].setupPlayer();
		if (data.gameType == SPLITSCREEN)
		{
			data.player[1].setupPlayer();
			data.playerAmount = 2;
		}
	}
}
