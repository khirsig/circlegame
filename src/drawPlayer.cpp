/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawPlayer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:47:24 by khirsig           #+#    #+#             */
/*   Updated: 2022/06/14 14:37:40 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/circlegame.hpp"

void drawPlayer(Data &data)
{
	for (int j = 0; j < data.playerAmount; ++j)
	{
		if (!gameover)
		{
			for (int i = 0; i < data.circleAmount; ++i)
			{
				if (data.player[j].collisionPlayer(data.circle[i]))
				{
					if (data.player[j].getActiveShield())
					{
						data.circle[i].resetCircle();
						data.player[j].setActiveShield(0);
					}
					else
					{
						gameover = 1;
						data.dyingPlayer = j;
					}
				}
			}
		}
		data.player[j].drawPlayer();
	}
}