/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actionsPlayer.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:12:20 by khirsig           #+#    #+#             */
/*   Updated: 2022/03/31 11:22:53 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circlegame.hpp"

void	changeMode(Data &data)
{
	if ((currentTime - startTime) % 10 == 0 && currentTime != data.modeTime)
	{
		int	newMode, currentMode = data.player.getMode();
		do
		{
			newMode = GetRandomValue(0, 3);
		} while (newMode == currentMode);
		data.player.setMode(newMode);
		data.modeTime = currentTime;
	}
}
