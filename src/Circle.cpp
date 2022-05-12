/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Circle.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 10:44:42 by khirsig           #+#    #+#             */
/*   Updated: 2022/05/05 11:04:22 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Circle.hpp"
#include <iostream>


int		Circle::_circleAmount = 0;
double	Circle::_modMinSpeed;
double	Circle::_modMaxSpeed;
int		Circle::_increaseTime = 0;

Circle::Circle()
{
	this->pos.x = 0;
	this->pos.y = 0;
	this->_active = 0;
}

Circle::~Circle()
{
	Circle::_circleAmount--;
}

void	Circle::updateSpeed()
{
	double	speed = GetRandomValue((float)screenWidth / 10 * Circle::_modMinSpeed, (float)screenWidth / 10 * Circle::_modMaxSpeed);
	this->speed = speed;
}

void	Circle::setDirection(int spawnDir)
{
	if (spawnDir == UP)
	{
		this->direction.x = GetRandomValue(0, screenWidth) - this->pos.x;
		this->direction.y = GetRandomValue(screenHeight / 4, screenHeight) - this->pos.y;
	}
	if (spawnDir == DOWN)
	{
		this->direction.x = GetRandomValue(0, screenWidth) - this->pos.x;
		this->direction.y = GetRandomValue(0, screenHeight / 4 * 3) - this->pos.y;
	}
	if (spawnDir == RIGHT)
	{
		this->direction.x = GetRandomValue(0, screenWidth  / 4 * 3) - this->pos.x;
		this->direction.y = GetRandomValue(0, screenHeight) - this->pos.y;
	}
	if (spawnDir == LEFT)
	{
		this->direction.x = GetRandomValue(screenWidth / 4, screenWidth) - this->pos.x;
		this->direction.y = GetRandomValue(0, screenHeight) - this->pos.y;
	}
	this->direction = Vector2Normalize(this->direction);
}

void	Circle::resetCircle()
{
	int	size = GetRandomValue(screenWidth / 42, screenWidth / 24);
	if (size < 1)
		size = 1;
	this->_size = size;
	Circle::updateSpeed();
	int colValue = GetRandomValue(70, 130);
	this->_color.r = colValue;
	this->_color.g = colValue;
	this->_color.b = colValue;
	int	spawnDir = GetRandomValue(0, 3);
	switch(spawnDir) {
		case UP :
			this->pos.x = GetRandomValue(this->_size, screenWidth - this->_size);
			this->pos.y = -this->_size;
			setDirection(spawnDir);
			break;
		case DOWN :
			this->pos.x = GetRandomValue(this->_size, screenWidth - this->_size);
			this->pos.y = screenHeight + this->_size;
			setDirection(spawnDir);
			break;
		case RIGHT :
			this->pos.x = screenWidth + this->_size;
			this->pos.y = GetRandomValue(this->_size, screenHeight - this->_size);
			setDirection(spawnDir);
			break;
		case LEFT :
			this->pos.x = -this->_size;
			this->pos.y = GetRandomValue(this->_size, screenHeight - this->_size);
			setDirection(spawnDir);
			break;
	}
}

void	Circle::moveCircle()
{
	if (this->_active)
	{
		this->pos.x += this->speed * this->direction.x / currentFPS;
		this->pos.y += this->speed * this->direction.y / currentFPS;
	}
	if ((this->pos.x < -this->_size || this->pos.x > screenWidth + this->_size || this->pos.y < -this->_size || this->pos.y > screenHeight + this->_size)
		&& this->_active)
		this->resetCircle();
}

void	Circle::drawCircle()
{
	if (this->_active)
		DrawCircle(this->pos.x, this->pos.y, this->_size, this->_color);
}

double	Circle::getCircleSize()
{
	return (this->_size);
}

void	Circle::activateCircle()
{
	this->_active = 1;
}

void	Circle::deactivateCircle()
{
	this->_active = 0;
}
