/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:25:35 by khirsig           #+#    #+#             */
/*   Updated: 2022/03/16 10:46:27 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

int		Data::getGameMode()
{
	return (this->_gameMode);
}

raylib::Window	&Data::getWindow()
{
	return (this->_window);
}

void	Data::setupWindow()
{
	this->window
	SetTargetFPS(SCREEN_FPS);
}


void	Data::setGameMode(int newGameMode)
{
	this->_gameMode = newGameMode;
}
