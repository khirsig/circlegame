/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:14:24 by khirsig           #+#    #+#             */
/*   Updated: 2022/05/23 15:43:09 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circlegame.hpp"

int		screenWidth;
int		screenHeight;
int		currentFPS;
int		currentTime;
int		startTime;
bool	gameover = false;
bool			darkMode;
raylib::Color	backgroundColor;


std::vector<int>	menuTextSize = {
	screenHeight / 8, screenHeight / 24, screenHeight / 36,
	screenHeight / 16, screenHeight / 28
};


int	main(void)
{
	if ((double)screenWidth / 16 != (double)screenHeight / 9)
	{
		std::cout << "Error: Use 16x9 width/height ratio." << std::endl;
		return (1);
	}
	Data data;

	loadSettings(data);
	for (int i = 0; i < data.circleAmount; ++i)
	{
		data.circle[i].activateCircle();
		data.circle[i].resetCircle();
	}
	for (int i = 0; i < 2; ++i)
	{
		data.player[i].setupPlayer();
		data.player[i].id = i;
	}
	data.user.elo.change = false;
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
				break ;
			case LOADING_SCREEN :
				loadingScreen(data);
				break ;
			case IN_GAME :
				ingame(data);
				break ;
			case ELO_SCREEN :
				eloScreen(data);
				break ;
			case OPTIONS :
				optionsScreen(data);
				break ;
		}
	}
	return (0);
}
