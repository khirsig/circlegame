/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Elo.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 17:36:47 by khirsig           #+#    #+#             */
/*   Updated: 2022/06/14 14:37:43 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/circlegame.hpp"

void	eloScreen(Data &data)
{
	if (IsKeyPressed(KEY_ENTER))
	{
			data.gameType = NOGAME;
			newRound(data);
	}

	int	eloSize = screenHeight / 4.0;
	raylib::Vector2	pos(0, 0);
	float scale;
	if (data.user.elo.rank <= 16)
	{
		scale = (float)eloSize / 4096;
		pos.x = screenWidth / 2 - scale * 2048;
	}
	else
	{
		scale = (float)eloSize / 300;
		pos.x = screenWidth / 2 - scale * 150;
	}
	pos.y = 0;

	BeginDrawing();
	DrawTextureEx(data.interface.eloImg[data.user.elo.rank], pos, 0, scale, WHITE);
	data.window.ClearBackground(backgroundColor);
	DrawText(eloName[data.user.elo.rank].c_str(), screenWidth / 2 - MeasureText(eloName[data.user.elo.rank].c_str(), menuTextSize[3]) / 2, screenHeight / 4, menuTextSize[3], eloColor[data.user.elo.rank]);
	std::string nbr(std::to_string(data.user.elo.points));
	if (data.user.elo.rank < 18)
		nbr += " / 100";
	raylib::Color col;
	if (darkMode)
		col = LIGHTGRAY;
	else
		col = DARKGRAY;
	DrawText(nbr.c_str(), screenWidth / 2 - MeasureText(nbr.c_str(), menuTextSize[4]) / 2, screenHeight / 3, menuTextSize[4], col);
	if (data.user.elo.gain > 0)
	{
		if (data.user.elo.change == true)
			nbr = "PROMOTED";
		else
		{
			nbr = "+";
			nbr += std::to_string(data.user.elo.gain);
		}
		DrawText(nbr.c_str(), screenWidth / 2 - MeasureText(nbr.c_str(), menuTextSize[4]) / 2, screenHeight / 3 + menuTextSize[4] * 1.5, menuTextSize[4], GREEN);
	}
	if (data.user.elo.gain < 0)
	{
		if (data.user.elo.change == true)
			nbr = "DEMOTED";
		else
			nbr = std::to_string(data.user.elo.gain);
		DrawText(nbr.c_str(), screenWidth / 2 - MeasureText(nbr.c_str(), menuTextSize[4]) / 2, screenHeight / 3 + menuTextSize[4] * 1.5, menuTextSize[4], RED);
	}
	if (data.user.elo.gain == 0)
	{
		nbr = std::to_string(data.user.elo.gain);
		DrawText(nbr.c_str(), screenWidth / 2 - MeasureText(nbr.c_str(), menuTextSize[4]) / 2, screenHeight / 3 + menuTextSize[4] * 1.5, menuTextSize[4], LIGHTGRAY);
	}
	EndDrawing();
}

static void	editTrend(Data &data)
{
	if (data.user.elo.gain > 0)
		data.user.elo.trend++;
	if (data.user.elo.gain < 0 || data.user.elo.gain == 0)
		data.user.elo.trend--;
	if (data.user.elo.gain > 25)
		data.user.elo.trend++;
	if (data.user.elo.gain < -25)
		data.user.elo.trend--;
	if (data.user.elo.trend > 10)
		data.user.elo.trend = 10;
	if (data.user.elo.trend < -10)
		data.user.elo.trend = -10;
}

void	calcElo(Data &data)
{
    std::cout << data.user.username << std::endl << data.user.password << std::endl << data.user.elo.rank << std::endl << data.user.elo.points << std::endl;
	int	points = currentTime - startTime;

	data.user.elo.gain = points - eloThreshold[data.user.elo.rank];
	if (data.user.elo.gain > 25)
		data.user.elo.gain = 25;
	if (data.user.elo.gain < -20)
		data.user.elo.gain = -20;
	editTrend(data);
	if (data.user.elo.points == 0 && data.user.elo.gain < 0)
		data.user.elo.points = -1;
	else
	{
		if (data.user.elo.gain > 0 && data.user.elo.gain + data.user.elo.trend <= 2)
			data.user.elo.gain = 2;
		else if (data.user.elo.gain < 0 && data.user.elo.gain + data.user.elo.trend >= -2)
			data.user.elo.gain = -2;
		else
			data.user.elo.gain += data.user.elo.trend;
		data.user.elo.points += data.user.elo.gain;
		if (data.user.elo.points < 0)
		{
			data.user.elo.gain -= data.user.elo.points;
			data.user.elo.points = 0;
		}
	}
	if (data.user.elo.points >= 100 && data.user.elo.rank < 18)
	{
		data.user.elo.rank++;
		data.user.elo.points -= 100;
		data.user.elo.change = true;
	}
	else if (data.user.elo.points < 0)
	{
		if (data.user.elo.rank == 0)
		{
			data.user.elo.points = 0;
			data.user.elo.gain = 0;
		}
		else
		{
			data.user.elo.rank--;
			data.user.elo.points = 75;
			data.user.elo.change = true;
		}
	}
	setEloServer(data);
}
