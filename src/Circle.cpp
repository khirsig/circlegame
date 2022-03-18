/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Circle.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 10:44:42 by khirsig           #+#    #+#             */
/*   Updated: 2022/03/18 12:16:18 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Circle.hpp"

int Circle::_circleAmount = 0;

Circle::Circle(int screenWidth, int screenHeight)
{
	Circle::_circleAmount++;
	this->resetCircle(screenWidth, screenHeight);
}

Circle::~Circle()
{
	Circle::_circleAmount--;
}

void	Circle::resetCircle(int screenWidth, int screenHeight)
{
	int	size = GetRandomValue(screenWidth / 32, screenWidth / 24);
	this->_size = size;
	int	speed = GetRandomValue(screenWidth / 1000 * 5.0, screenWidth / 1000 * 7.5);
	this->_speed = speed;
	int	spawnDir = GetRandomValue(0, 3);
	switch(spawnDir) {
		case UP :
			this->_pos.x = GetRandomValue(this->_size, screenWidth - this->_size);
			this->_pos.y = -this->_size;
			this->_moveDir = DOWN;
			break;
		case DOWN :
			this->_pos.x = GetRandomValue(this->_size, screenWidth - this->_size);
			this->_pos.y = screenHeight + this->_size;
			this->_moveDir = UP;
			break;
		case RIGHT :
			this->_pos.x = screenWidth + this->_size;
			this->_pos.y = GetRandomValue(this->_size, screenHeight - this->_size);
			this->_moveDir = LEFT;
			break;
		case LEFT :
			this->_pos.x = -this->_size;
			this->_pos.y = GetRandomValue(this->_size, screenHeight - this->_size);
			this->_moveDir = RIGHT;
			break;
			break;
	}
	_color = DARKGRAY;
}

void	Circle::moveCircle(int screenWidth, int screenHeight)
{
	switch(this->_moveDir) {
		case UP :
			this->_pos.y -= this->_speed;
			break;
		case DOWN :
			this->_pos.y += this->_speed;
			break;
		case RIGHT :
			this->_pos.x += this->_speed;
			break;
		case LEFT :
			this->_pos.x -= this->_speed;
			break;
	}
	if (this->_pos.x < -this->_size || this->_pos.x > screenWidth + this->_size || this->_pos.y < -this->_size || this->_pos.y > screenHeight + this->_size)
		this->resetCircle(screenWidth, screenHeight);
}

void	Circle::drawCircle()
{
	DrawCircle(this->_pos.x, this->_pos.y, this->_size, this->_color);
}
