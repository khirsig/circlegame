/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadingScreen.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:13:18 by khirsig           #+#    #+#             */
/*   Updated: 2022/03/16 12:45:34 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circlegame.hpp"

void	loadingScreen(Data &data)
{
	BeginDrawing();
	data.window.ClearBackground(RAYWHITE);
	EndDrawing();
}
