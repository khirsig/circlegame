/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:14:24 by khirsig           #+#    #+#             */
/*   Updated: 2022/03/23 12:31:52 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circlegame.hpp"

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
		data.circle[i].resetCircle(data.screenWidth, data.screenHeight);
	}
	data.player.setupPlayer(data.screenWidth, data.screenHeight);
	SetTargetFPS(SCREEN_FPS);
	while (!(data.window.ShouldClose()))
	{
		switch (data.gameMode)
		{
			case START_SCREEN :
				startScreen(data);
				break;
			case IN_GAME :
				ingame(data);
				break;
		}
	}
	return (0);
}
