/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:28:38 by khirsig           #+#    #+#             */
/*   Updated: 2022/03/29 14:27:14 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circlegame.hpp"

float getRandomNumber(float min, float max)
{
    static std::default_random_engine engine;
    static std::uniform_real_distribution<> ret(min, max);
    return ret(engine);
}

void    setCurrentTime(Data &data)
{
    data.currentTime = GetTime();
}

void    setStartTime(Data &data)
{
    data.startTime = GetTime();
}

void    newRound(Data &data)
{
    for (int i = 0; i < data.circleAmount; ++i)
	{
		data.circle[i].activateCircle();
		data.circle[i].resetCircle();
	}
	data.player.setupPlayer();
	data.gameMode = START_SCREEN;
	data.gameover = 0;
    setStartTime(data);
    setCurrentTime(data);
    data.modeTime = data.currentTime;
}

void    setFPS(Data &data)
{
    currentFPS = GetFPS();
}
