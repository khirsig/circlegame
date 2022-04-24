/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elo.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 17:36:47 by khirsig           #+#    #+#             */
/*   Updated: 2022/04/24 18:41:14 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circlegame.hpp"

void	eloScreen(Data &data)
{
		if (IsKeyPressed(KEY_ENTER))
			newRound(data);
	BeginDrawing();
	data.window.ClearBackground(RAYWHITE);
	DrawText(eloName[data.elo.rank].c_str(), screenWidth / 2 - MeasureText(eloName[data.elo.rank].c_str(), menuTextSize[3]) / 2, screenHeight / 4, menuTextSize[3], eloColor[data.elo.rank]);
	std::string nbr(std::to_string(data.elo.points));
	nbr += " / 100";
	DrawText(nbr.c_str(), screenWidth / 2 - MeasureText(nbr.c_str(), menuTextSize[4]) / 2, screenHeight / 3, menuTextSize[4], DARKGRAY);
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
				data.elo.points = 0;
		}
		if (data.elo.points >= 100 && data.elo.rank < 21)
		{
			data.elo.rank++;
			data.elo.points -= 100;;
		}
		if (data.elo.points < 0)
		{
			if (data.elo.rank == 0)
				data.elo.points = 0;
			else
			{
				data.elo.rank--;
				data.elo.points = 75;
			}
		}
	}
	std::cout << "Rank: " << data.elo.rank << std::endl << "Elo Points: " << data.elo.points << " / 100" << std::endl;
	std::cout << "Ingame Points: " << points << std::endl;
	SaveStorageValue(0, data.elo.rank);
	SaveStorageValue(1, data.elo.points);
}
