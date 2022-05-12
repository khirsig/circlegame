/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actionsPlayer.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:12:20 by khirsig           #+#    #+#             */
/*   Updated: 2022/05/05 11:03:58 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circlegame.hpp"

void	changeMode(Data &data)
{
	if ((currentTime - startTime) % 10 == 0 && currentTime != data.modeTime)
	{
		for (int i = 0; i < data.playerAmount; ++i)
		{
			int	newMode, currentMode = data.player[i].getMode();
			do
			{
				newMode = GetRandomValue(0, 4);
			} while (newMode == currentMode);
			data.player[i].setMode(newMode);
		}
		data.modeTime = currentTime;
	}
}

static void playerUsePowerUp(Data &data, Player &player)
{
    int powerUpHold = player.getPowerUpHold();
     switch (powerUpHold) {
        case SHIELD :
            player.setShieldTimer(currentTime + 10);
            player.setActiveShield(1);
            player.setPowerUpHold(NONE);
            break ;
        case SKIPMODE :
            player.setMode(STANDARD);
            player.setPowerUpHold(NONE);
            break ;
        case IMPULSE :
			player.activeImpulse = true;
			player.impulseRadius = 0.0f;
			player.impulseStatus = 0;
			player.impulsePos = player.getPos();
			player.impulseColor.a = 150;
            player.setPowerUpHold(NONE);
            break ;
    }
}

void    usePowerUp(Data &data)
{
    if (IsKeyPressed(KEY_SPACE))
        playerUsePowerUp(data, data.player[0]);
    if (IsKeyPressed(KEY_RIGHT_CONTROL) && data.playerAmount > 1)
        playerUsePowerUp(data, data.player[1]);
    for (int i = 0; i < data.playerAmount; ++i)
    {
        if (data.player[i].getShieldTimer() == currentTime && data.player[i].getActiveShield() == 1)
        {
            data.player[i].setActiveShield(0);
        }
    }
}

void	impulseHit(Data &data)
{
	for (int j = 0; j < data.playerAmount; ++j)
	{
		if (data.player[j].activeImpulse)
		{
			for (int i = 0; i < data.circleAmount; ++i)
			{
				if (CheckCollisionCircles(data.circle[i].pos, data.circle[i].getCircleSize(), data.player[j].impulsePos, data.player[j].impulseRadius))
				{
					data.circle[i].resetCircle();
				}
			}
		}
	}
}
