/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startScreen.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:13:18 by khirsig           #+#    #+#             */
/*   Updated: 2022/03/16 10:35:42 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circlegame.hpp"

void	startScreen(Data &data)
{
	BeginDrawing();
	data.getWindow().ClearBackground(BLACK);
	EndDrawing();
}
