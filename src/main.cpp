/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:14:24 by khirsig           #+#    #+#             */
/*   Updated: 2022/04/27 14:55:58 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circlegame.hpp"

int		screenWidth = SCREEN_WIDTH;
int		screenHeight = SCREEN_HEIGHT;
int		currentFPS;
int		currentTime;
int		startTime;

int	main(void)
{
	if ((double)SCREEN_WIDTH / 16 != (double)SCREEN_HEIGHT / 9)
	{
		std::cout << "Error: Use 16x9 width/height ratio." << std::endl;
		return (1);
	}
	Data data;

	for (int i = 0; i < data.circleAmount; ++i)
	{
		data.circle[i].activateCircle();
		data.circle[i].resetCircle();
	}
	for (int i = 0; i < data.playerAmount; ++i)
	{
		data.player[i].setupPlayer();
		data.player[i].id = i;
	}
	data.elo.change = false;
	data.elo.trend = 0;
	SetTargetFPS(SCREEN_FPS);
	while (!(data.window.ShouldClose()))
	{
		setFPS(data);
		switch (data.gameMode)
		{
			case PRE_START :
				loadResources(data);
			case START_SCREEN :
				startScreen(data);
				break;
			case LOADING_SCREEN :
				loadingScreen(data);
				break;
			case IN_GAME :
				ingame(data);
				break;
			case ELO_SCREEN :
				eloScreen(data);
				break;
		}
	}
	return (0);
}
