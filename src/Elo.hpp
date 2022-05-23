/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Elo.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 17:12:57 by khirsig           #+#    #+#             */
/*   Updated: 2022/05/23 09:34:35 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

const static int eloThreshold[19] = { 5, 5, 5, 10, 10, 10, 15, 15, 15, 20,
									20, 20, 25, 25, 25, 30, 30, 30, 30 };
const static float eloSpeed[19] = { 1.0f, 1.1f, 1.3f, 1.5f, 1.6f, 1.8f, 2.0f, 2.2f, 2.4f, 2.6f,
									3.0f, 3.5f, 3.6f, 3.8f, 4.0f, 4.2f, 4.4f, 4.5f, 5.0f };
const static std::string eloName[19] = { "Sapphire 1", "Sapphire 2", "Sapphire 3", "Emerald 1", "Emerald 2", "Emerald 3",
										"Silver 1", "Silver 2", "Silver 3", "Gold 1", "Gold 2", "Gold 3",
										"Platin 1", "Platin 2", "Platin 3", "Diamond 1", "Diamond 2",
										"Diamond 3", "Immortal" };
const static raylib::Color eloColor[19] = { BLUE, BLUE, BLUE, LIME, LIME, LIME, LIGHTGRAY, LIGHTGRAY, LIGHTGRAY,
											GOLD, GOLD, GOLD, DARKGREEN, DARKGREEN, DARKGREEN, SKYBLUE, SKYBLUE, SKYBLUE,
											VIOLET };
struct Elo {
	int		points;
	int		rank;
	int		gain;
	int		trend;
	bool	change;

	JS_OBJ(points, rank, trend);
};
