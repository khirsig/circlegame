/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlayerModes.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 13:56:44 by khirsig           #+#    #+#             */
/*   Updated: 2022/03/30 14:28:03 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"

void	Player::growthMode()
{
	if (this->_growthDir == 1 && this->_size >= this->_growthBase * 1.5)
		this->_growthDir = 0;
	else if (this->_growthDir == 0 && this->_size <= this->_growthBase * 0.5)
		this->_growthDir = 1;
	if (this->_growthDir == 1)
		this->_size += 2000 / currentFPS;
	else
		this->_size -= 2000 / currentFPS;
}
