/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:26:53 by khirsig           #+#    #+#             */
/*   Updated: 2022/03/28 10:02:07 by khirsig          ###   ########.fr       */
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
		default :
			col.r = 190;
			col.g = 33;
			col.b = 55;
			break ;

	}
}

void	Player::setupPlayer(int screenWidth, int screenHeight)
{
	this->_size = screenWidth / 40;
	this->_speed = screenWidth / 1000 * 7.0;
	this->_pos.x = screenWidth / 2 - (this->_size / 2);
	this->_pos.y = screenHeight / 2 - (this->_size / 2);
	this->_mode = MIRROR_ICE;
	setColor(this->_color, this->_mode);
	this->_moveDir = KEY_RIGHT;
}

void	Player::drawPlayer()
{
	DrawCircle(this->_pos.x, this->_pos.y, this->_size, this->_color);
}

void	Player::movePlayerStandard(int screenWidth, int screenHeight)
{
	if ((IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) && this->_pos.y - this->_speed >= this->_size * 0.90)
		this->_pos.y -= this->_speed;
	if ((IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) && this->_pos.y + this->_speed <= screenHeight - this->_size * 0.90)
		this->_pos.y += this->_speed;
	if ((IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) && this->_pos.x + this->_speed <= screenWidth - this->_size * 0.90)
		this->_pos.x += this->_speed;
	if ((IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) && this->_pos.x - this->_speed >= this->_size * 0.90)
		this->_pos.x -= this->_speed;
}

void	Player::movePlayerIce(int screenWidth, int screenHeight)
{
	double	slideSpeed = this->_speed * 0.70;

	if (_moveDir == KEY_UP && this->_pos.y - slideSpeed >= this->_size * 0.90)
		this->_pos.y -= slideSpeed;
	if (_moveDir == KEY_DOWN && this->_pos.y + slideSpeed <= screenHeight - this->_size * 0.90)
		this->_pos.y += slideSpeed;
	if (_moveDir == KEY_RIGHT && this->_pos.x + slideSpeed <= screenWidth - this->_size * 0.90)
		this->_pos.x += slideSpeed;
	if (_moveDir == KEY_LEFT && this->_pos.x - slideSpeed >= this->_size * 0.90)
		this->_pos.x -= slideSpeed;
}

void	Player::movePlayerMirrorIce(int screenWidth, int screenHeight)
{
	double	slideSpeed = this->_speed * 0.70;

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
