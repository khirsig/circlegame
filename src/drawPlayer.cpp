/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawPlayer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:47:24 by khirsig           #+#    #+#             */
/*   Updated: 2022/03/30 14:12:43 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circlegame.hpp"

void drawPlayer(Data &data)
{
	if (!data.gameover)
	{
		for (int i = 0; i < data.circleAmount; ++i)
		{
			if (data.player.collisionPlayer(data.circle[i]))
			{
				if (data.player.getActiveShield())
				{
					data.circle[i].resetCircle();
					data.player.setActiveShield(0);
				}
				else
					data.gameover = 1;
			}
		}
	}
	data.player.drawPlayer();
}