/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movePlayer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:54:00 by khirsig           #+#    #+#             */
/*   Updated: 2022/03/23 13:47:11 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circlegame.hpp"

static void	setMoveDir(Data &data)
{
	int key = GetKeyPressed();
	if (key == KEY_UP || key == KEY_W)
		data.player.setMoveDir(KEY_UP);
	if (key == KEY_DOWN || key == KEY_S)
		data.player.setMoveDir(KEY_DOWN);
	if (key == KEY_LEFT || key == KEY_A)
		data.player.setMoveDir(KEY_LEFT);
	if (key == KEY_RIGHT || key == KEY_D)
		data.player.setMoveDir(KEY_RIGHT);
}

void	movePlayer(Data &data)
{
	setMoveDir(data);
	switch (data.player.getMode()) {
		case ICE :
			data.player.movePlayerIce(data.screenWidth, data.screenHeight);
			break ;
		case MIRROR_ICE :
			data.player.movePlayerMirrorIce(data.screenWidth, data.screenHeight);
			break ;
		default :
			data.player.movePlayerStandard(data.screenWidth, data.screenHeight);
			break ;
	}
}
