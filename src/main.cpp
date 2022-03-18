/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:14:24 by khirsig           #+#    #+#             */
/*   Updated: 2022/03/18 13:55:42 by khirsig          ###   ########.fr       */
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

	data.circle = new Circle(data.screenWidth, data.screenHeight);
	// for (int i = 0; i < data.circleAmount; ++i)
		// data.circle[i] = data.circle(data.screenWidth, data.screenHeight);
	SetTargetFPS(SCREEN_FPS);
	while (!(data.window.ShouldClose()))
	{
		switch (data.gameMode)
		{
			case START_SCREEN :
				startScreen(data);
				break;
			case LOADING_SCREEN :
				loadingScreen(data);
				break;
		}
	}
	return (0);
}
