/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:26:53 by khirsig           #+#    #+#             */
/*   Updated: 2022/03/23 12:41:46 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"

Player::Player()
{
	this->_pos.x = -50;
	this->_pos.y = -50;
}

Player::~Player() { }

void	Player::setupPlayer(int screenWidth, int screenHeight)
{
	this->_size = screenWidth / 40;
	this->_speed = screenWidth / 1000 * 7.0;
	this->_color.r = 225;
	this->_color.g = 50;
	this->_color.b = 50;
	this->_pos.x = screenWidth / 2 - (this->_size / 2);
	this->_pos.y = screenHeight / 2 - (this->_size / 2);
	this->_mode = 0;
}

void	Player::drawPlayer()
{
	DrawCircle(this->_pos.x, this->_pos.y, this->_size, this->_color);
}

void	Player::movePlayer(int screenWidth, int screenHeight)
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

bool	Player::collisionPlayer(Circle circle)
{
	return (CheckCollisionCircles(this->_pos, this->_size, circle.getCirclePos(), circle.getCircleSize()));
}
