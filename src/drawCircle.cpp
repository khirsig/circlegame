/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawCircle.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 10:44:47 by khirsig           #+#    #+#             */
/*   Updated: 2022/03/29 14:21:25 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circlegame.hpp"

void drawCircle(Data &data)
{
	for (int i = 0; i < data.circleAmount; ++i)
	{
		if (!data.gameover)
			data.circle[i].moveCircle();
		data.circle[i].drawCircle();
	}
}
