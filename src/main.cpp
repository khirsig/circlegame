/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:14:24 by khirsig           #+#    #+#             */
/*   Updated: 2022/04/07 15:45:53 by khirsig          ###   ########.fr       */
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
	SetTargetFPS(SCREEN_FPS);
	while (!(data.window.ShouldClose()))
	{
		setFPS(data);
		switch (data.gameMode)
		{
			case START_SCREEN :
				startScreen(data);
				break;
			case LOADING_SCREEN :
				loadingScreen(data);
				break;
			case IN_GAME :
				ingame(data);
				break;
		}
	}
	return (0);
}
