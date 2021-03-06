/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startScreen.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:13:18 by khirsig           #+#    #+#             */
/*   Updated: 2022/06/14 14:38:17 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/circlegame.hpp"

static void	moveThroughMenu(Data &data)
{
	int			inputKey;

	inputKey = GetKeyPressed();
	if (inputKey == KEY_UP || inputKey == KEY_W)
	{
		if (data.interface.mainMenuButton == -1)
			data.interface.mainMenuButton = 0;
		else if (data.interface.mainMenuButton > 0)
			data.interface.mainMenuButton--;
		else
			data.interface.mainMenuButton = 4;
	}
	if (inputKey == KEY_DOWN || inputKey == KEY_S)
	{
		if (data.interface.mainMenuButton == -1)
			data.interface.mainMenuButton = 0;
		else if (data.interface.mainMenuButton < 4)
			data.interface.mainMenuButton++;
		else
			data.interface.mainMenuButton = 0;
	}
}

bool	drawMenuText(Data &data, int id, const char *text, int posX, int posY, int textSize)
{
	raylib::Color col;
	moveThroughMenu(data);
	if (moveThroughMenuMouse(posX, posY, MeasureText(text, textSize), textSize) || data.interface.mainMenuButton == id)
	{
		col = RED;
		data.interface.mainMenuButton = id;
	}
	else
	{
		if (darkMode)
			col = LIGHTGRAY;
		else
			col = DARKGRAY;
	}
	DrawText(text, posX, posY, textSize, col);
	if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE)) && data.interface.mainMenuButton == id)
		return (true);
	else
		return (false);
}

void	startScreen(Data &data)
{
	BeginDrawing();
	data.window.ClearBackground(backgroundColor);
	drawCircle(data);
	checkCircleCollision(data);
	DrawText(menuText[0].c_str(), screenWidth / 2 - MeasureText(menuText[0].c_str(), menuTextSize[0]) / 2, screenHeight / 8, menuTextSize[0], BLUE);
	if (drawMenuText(data, 0, mainMenuText[0].c_str(), screenWidth / 2 - MeasureText(mainMenuText[0].c_str(), menuTextSize[1]) / 2, screenHeight / 8 * 3, menuTextSize[1]))
		data.gameType = NORMALGAME;
	if (drawMenuText(data, 1, mainMenuText[1].c_str(), screenWidth / 2 - MeasureText(mainMenuText[1].c_str(), menuTextSize[1]) / 2, screenHeight / 8 * 4, menuTextSize[1]))
		data.gameType = RANKEDGAME;
	if (drawMenuText(data, 2, mainMenuText[2].c_str(), screenWidth / 2 - MeasureText(mainMenuText[2].c_str(), menuTextSize[1]) / 2, screenHeight / 8 * 5, menuTextSize[1]))
		data.gameType = SPLITSCREEN;
	if (drawMenuText(data, 3, mainMenuText[3].c_str(), screenWidth / 2 - MeasureText(mainMenuText[3].c_str(), menuTextSize[1]) / 2, screenHeight / 8 * 6, menuTextSize[1]))
		data.gameMode = OPTIONS;
	if (drawMenuText(data, 4, mainMenuText[4].c_str(), screenWidth / 2 - MeasureText(mainMenuText[4].c_str(), menuTextSize[1]) / 2, screenHeight / 8 * 7, menuTextSize[1]))
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
