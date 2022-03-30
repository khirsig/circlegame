/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerUp.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 09:41:30 by khirsig           #+#    #+#             */
/*   Updated: 2022/03/30 14:18:24 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PowerUp.hpp"

PowerUp::PowerUp()
{
	// this->resetPowerUp();
}

void	PowerUp::resetPowerUp()
{
	this->_id = GetRandomValue(0, 1);
	this->_state = SPAWNED;
	this->_sizeEnd = screenWidth / 42;
	this->_sizeCurrent = 1;
	this->_pos.x = GetRandomValue(this->_sizeEnd * 1.5, screenWidth - (this->_sizeEnd * 1.5));
	this->_pos.y = GetRandomValue(this->_sizeEnd * 1.5, screenHeight - (this->_sizeEnd * 1.5));
}

void	PowerUp::drawPowerUp()
{
	DrawCircle(this->_pos.x, this->_pos.y, this->_sizeCurrent, ORANGE);
	if (this->_sizeCurrent > 5)
		DrawText("?", this->_pos.x - this->_sizeCurrent / 4, this->_pos.y - this->_sizeCurrent / 2, this->_sizeCurrent, RAYWHITE);
	if (this->_state == SPAWNED && this->_sizeCurrent < this->_sizeEnd)
		this->_sizeCurrent += 0.05;
	if (this->_state == DESPAWNING)
	{
		this->_sizeCurrent -= 0.05;
		if (this->_sizeCurrent <= 0)
		{
			this->_state = DESPAWNED;
		}
	}
}

void	PowerUp::activatePowerUp()
{

}

void	PowerUp::passivePowerUp()
{

}
