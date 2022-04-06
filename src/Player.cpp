/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:26:53 by khirsig           #+#    #+#             */
/*   Updated: 2022/04/06 14:16:31 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"

Player::Player()
{
	this->_pos.x = -50;
	this->_pos.y = -50;
}

Player::~Player() { }

static void	setColor(raylib::Color &col, const int mode)
{
	switch (mode) {
		case ICE :
			col.r = 102;
			col.g = 191;
			col.b = 255;
			break ;
		case MIRROR_ICE :
			col.r = 0;
			col.g = 117;
			col.b = 117;
			break ;
		case GROWTH :
			col.r = 100;
			col.g = 22;
			col.b = 255;
			break ;
		default :
			col.r = 190;
			col.g = 33;
			col.b = 55;
			break ;

	}
}

void	Player::setupPlayer()
{
	this->_size = screenWidth / 40;
	this->_growthBase = screenWidth / 40;
	this->_speed = screenWidth / 10 * 5.5;
	this->_pos.y = screenHeight / 2 - (this->_size / 2);
	this->_mode = STANDARD;
	setColor(this->_color, this->_mode);
	this->_moveDir = KEY_RIGHT;
	this->_growthDir = 1;
	if (this->id == 0)
	{
		this->_pos.x = screenWidth / 4 - (this->_size / 2);
		this->_playerColor.r = 230;
		this->_playerColor.g = 41;
		this->_playerColor.b = 55;
	}
	else
	{
		this->_pos.x = screenWidth / 4 * 3 - (this->_size / 2);
		this->_playerColor.r = 0;
		this->_playerColor.g = 121;
		this->_playerColor.b = 242;
	}
	this->_playerColor.a = 255;
	this->_powerUpHold = -1;
	this->_activeShield = 0;
}

void	Player::setMode(int id)
{
	this->_mode = id;
	setColor(this->_color, this->_mode);
	this->_size = screenWidth / 40;
}


void	Player::drawPlayer()
{
	if (this->_activeShield)
		DrawCircle(this->_pos.x, this->_pos.y, this->_size * 1.1, MAGENTA);
	DrawCircle(this->_pos.x, this->_pos.y, this->_size, this->_color);
	DrawCircle(this->_pos.x, this->_pos.y, this->_size * 0.8, this->_playerColor);
}

void	Player::movePlayerStandard()
{
	double	currentSpeed = this->_speed / currentFPS;
	if (((IsKeyDown(KEY_W) && this->id == 0) || (IsKeyDown(KEY_UP) && this->id == 1)) && this->_pos.y - currentSpeed >= this->_size * 0.90)
		this->_pos.y -= currentSpeed;
	if (((IsKeyDown(KEY_S) && this->id == 0) || (IsKeyDown(KEY_DOWN) && this->id == 1)) && this->_pos.y + currentSpeed <= screenHeight - this->_size * 0.90)
		this->_pos.y += currentSpeed;
	if (((IsKeyDown(KEY_D) && this->id == 0) || (IsKeyDown(KEY_RIGHT) && this->id == 1)) && this->_pos.x + currentSpeed <= screenWidth - this->_size * 0.90)
		this->_pos.x += currentSpeed;
	if (((IsKeyDown(KEY_A) && this->id == 0) || (IsKeyDown(KEY_LEFT) && this->id == 1)) && this->_pos.x - currentSpeed >= this->_size * 0.90)
		this->_pos.x -= currentSpeed;
}

void	Player::movePlayerIce()
{
	double	slideSpeed = this->_speed * 0.70 / currentFPS;

	if (_moveDir == KEY_UP && this->_pos.y - slideSpeed >= this->_size * 0.90)
		this->_pos.y -= slideSpeed;
	if (_moveDir == KEY_DOWN && this->_pos.y + slideSpeed <= screenHeight - this->_size * 0.90)
		this->_pos.y += slideSpeed;
	if (_moveDir == KEY_RIGHT && this->_pos.x + slideSpeed <= screenWidth - this->_size * 0.90)
		this->_pos.x += slideSpeed;
	if (_moveDir == KEY_LEFT && this->_pos.x - slideSpeed >= this->_size * 0.90)
		this->_pos.x -= slideSpeed;
}

void	Player::movePlayerMirrorIce()
{
	double	slideSpeed = this->_speed * 0.70 / currentFPS;

	if (_moveDir == KEY_DOWN && this->_pos.y - slideSpeed >= this->_size * 0.90)
		this->_pos.y -= slideSpeed;
	if (_moveDir == KEY_UP && this->_pos.y + slideSpeed <= screenHeight - this->_size * 0.90)
		this->_pos.y += slideSpeed;
	if (_moveDir == KEY_LEFT && this->_pos.x + slideSpeed <= screenWidth - this->_size * 0.90)
		this->_pos.x += slideSpeed;
	if (_moveDir == KEY_RIGHT && this->_pos.x - slideSpeed >= this->_size * 0.90)
		this->_pos.x -= slideSpeed;
}

void	Player::setMoveDir(int input)
{
	this->_moveDir = input;
}

bool	Player::collisionPlayer(Circle circle)
{
	return (CheckCollisionCircles(this->_pos, this->_size, circle.getCirclePos(), circle.getCircleSize()));
}

void	Player::modeExec()
{
	if (this->_mode == GROWTH)
		growthMode();
}
