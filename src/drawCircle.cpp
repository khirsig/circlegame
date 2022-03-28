/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawCircle.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 10:44:47 by khirsig           #+#    #+#             */
/*   Updated: 2022/03/22 15:08:19 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circlegame.hpp"

void drawCircle(Data &data)
{
	for (int i = 0; i < data.circleAmount; ++i)
	{
		if (!data.gameover)
			data.circle[i].moveCircle(data.screenWidth, data.screenHeight);
		data.circle[i].drawCircle();
	}
}