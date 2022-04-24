/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elo.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 17:36:47 by khirsig           #+#    #+#             */
/*   Updated: 2022/04/24 19:59:05 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circlegame.hpp"

void	eloScreen(Data &data)
{
	if (IsKeyPressed(KEY_ENTER))
			newRound(data);

	int	eloSize = screenHeight / 4.0;
	raylib::Vector2	pos(0, 0);
	float scale = (float)eloSize / 300;
	pos.x = screenWidth / 2 - scale * 150;
	pos.y = 0;

	BeginDrawing();
	DrawTextureEx(data.interface.eloImg[data.elo.rank], pos, 0, scale, WHITE);
	data.window.ClearBackground(RAYWHITE);
	DrawText(eloName[data.elo.rank].c_str(), screenWidth / 2 - MeasureText(eloName[data.elo.rank].c_str(), menuTextSize[3]) / 2, screenHeight / 4, menuTextSize[3], eloColor[data.elo.rank]);
	std::string nbr(std::to_string(data.elo.points));
	nbr += " / 100";
	DrawText(nbr.c_str(), screenWidth / 2 - MeasureText(nbr.c_str(), menuTextSize[4]) / 2, screenHeight / 3, menuTextSize[4], DARKGRAY);
	if (data.elo.gain > 0)
	{
		if (data.elo.change == true)
			nbr = "PROMOTED";
		else;
		{
			nbr = "+";
			nbr += std::to_string(data.elo.gain);
		}
		DrawText(nbr.c_str(), screenWidth / 2 - MeasureText(nbr.c_str(), menuTextSize[4]) / 2, screenHeight / 3 + menuTextSize[4] * 1.5, menuTextSize[4], GREEN);
	}
	if (data.elo.gain < 0)
	{
		if (data.elo.change == true)
			nbr = "DEMOTED";
		else
			nbr = std::to_string(data.elo.gain);
		DrawText(nbr.c_str(), screenWidth / 2 - MeasureText(nbr.c_str(), menuTextSize[4]) / 2, screenHeight / 3 + menuTextSize[4] * 1.5, menuTextSize[4], RED);
	}
	if (data.elo.gain == 0)
	{
		nbr = std::to_string(data.elo.gain);
		DrawText(nbr.c_str(), screenWidth / 2 - MeasureText(nbr.c_str(), menuTextSize[4]) / 2, screenHeight / 3 + menuTextSize[4] * 1.5, menuTextSize[4], LIGHTGRAY);
	}
	EndDrawing();
}

void	calcElo(Data &data)
{
	int	points = currentTime - startTime;

	if (points != eloThreshold[data.elo.rank])
	{
		data.elo.gain = points - eloThreshold[data.elo.rank];
		if (data.elo.gain > 25)
			data.elo.gain = 25;
		if (data.elo.gain < -20)
			data.elo.gain = -20;
		if (data.elo.points == 0 && data.elo.gain < 0)
			data.elo.points = -1;
		else
		{
			data.elo.points += data.elo.gain;
			if (data.elo.points < 0)
			{
				data.elo.gain -= data.elo.points;
				data.elo.points = 0;
			}
		}
		if (data.elo.points >= 100 && data.elo.rank < 18)
		{
			data.elo.rank++;
			data.elo.points -= 100;;
			data.elo.change = true;
		}
		if (data.elo.points < 0)
		{
			if (data.elo.rank == 0)
			{
				data.elo.points = 0;
				data.elo.gain = 0;
			}
			else
			{
				data.elo.rank--;
				data.elo.points = 75;
				data.elo.change = true;
			}
		}
	}
	SaveStorageValue(0, data.elo.rank);
	SaveStorageValue(1, data.elo.points);
}
