/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:14:24 by khirsig           #+#    #+#             */
/*   Updated: 2022/03/16 12:43:45 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circlegame.hpp"

int	main(void)
{
	Data data;

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
