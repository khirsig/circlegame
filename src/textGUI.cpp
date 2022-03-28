/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textGUI.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:11:59 by khirsig           #+#    #+#             */
/*   Updated: 2022/03/28 16:01:38 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circlegame.hpp"

#define MODE_STR modeText[data.player.getMode()].c_str()

void	modeGUI(Data &data)
{
	int	modeSize = data.screenHeight / 36;

	DrawText(MODE_STR, data.screenWidth / 2 - MeasureText(MODE_STR, modeSize) / 2, modeSize / 2, modeSize, data.player.getColor());
}

void	timeGUI(Data &data)
{
	int	timeSize = data.screenHeight / 30;
	std::string timeText = std::to_string(data.currentTime - data.startTime);
	int	timeLen = MeasureText(timeText.c_str(), timeSize);
	Color timeCol = (Color){ 0, 121, 241, 255 };

	DrawText(timeText.c_str(), timeSize, data.screenHeight - timeSize * 1.5, timeSize, timeCol);
}
