/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actionsPlayer.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:12:20 by khirsig           #+#    #+#             */
/*   Updated: 2022/04/26 10:25:27 by khirsig          ###   ########.fr       */
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
