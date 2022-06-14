/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlayerModes.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 13:56:44 by khirsig           #+#    #+#             */
/*   Updated: 2022/06/14 14:38:13 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Player.hpp"

void	Player::growthMode()
{
	if (this->_growthDir == 1 && this->_size >= this->_growthBase * 1.8)
		this->_growthDir = 0;
	else if (this->_growthDir == 0 && this->_size <= this->_growthBase * 0.2)
		this->_growthDir = 1;
	if (this->_growthDir == 1)
		this->_size += 50.0 / currentFPS;
	else
		this->_size -= 50.0 / currentFPS;
}
