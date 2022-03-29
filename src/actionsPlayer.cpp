/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actionsPlayer.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:12:20 by khirsig           #+#    #+#             */
/*   Updated: 2022/03/29 14:07:31 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circlegame.hpp"

void	changeMode(Data &data)
{
	if ((data.currentTime - data.startTime) % 10 == 0 && data.currentTime != data.modeTime)
	{
		int	newMode, currentMode = data.player.getMode();
		do
		{
			newMode = GetRandomValue(0, 3);
		} while (newMode == currentMode);
		data.player.setMode(newMode);
		data.modeTime = data.currentTime;
	}
}
