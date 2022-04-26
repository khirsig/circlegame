/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movePlayer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:54:00 by khirsig           #+#    #+#             */
/*   Updated: 2022/04/26 10:26:46 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circlegame.hpp"

static void	setMoveDir(Data &data)
{
	int key = GetKeyPressed();
	if (key == KEY_W)
		data.player[0].setMoveDir(KEY_UP);
	if (key == KEY_S)
		data.player[0].setMoveDir(KEY_DOWN);
	if (key == KEY_A)
		data.player[0].setMoveDir(KEY_LEFT);
	if (key == KEY_D)
		data.player[0].setMoveDir(KEY_RIGHT);
	if (data.playerAmount > 1)
	{
		if (key == KEY_UP)
			data.player[1].setMoveDir(KEY_UP);
		if (key == KEY_DOWN)
			data.player[1].setMoveDir(KEY_DOWN);
		if (key == KEY_LEFT)
			data.player[1].setMoveDir(KEY_LEFT);
		if (key == KEY_RIGHT)
			data.player[1].setMoveDir(KEY_RIGHT);
	}
}

void	movePlayer(Data &data)
{
	setMoveDir(data);
	for (int i = 0; i < data.playerAmount; ++i)
	{
		switch (data.player[i].getMode()) {
			case ICE :
				data.player[i].movePlayerIce();
				break ;
			case MIRROR_ICE :
				data.player[i].movePlayerMirrorIce();
				break ;
			case MIRROR :
				data.player[i].movePlayerMirror();
				break ;
			default :
				data.player[i].movePlayerStandard();
				break ;
		}
	}
}
