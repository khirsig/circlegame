/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Elo.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 17:12:57 by khirsig           #+#    #+#             */
/*   Updated: 2022/04/27 13:21:56 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELO_HPP
# define ELO_HPP

const static int eloThreshold[19] = { 3, 5, 8, 10, 12, 13, 15, 17, 20, 25,
									30, 40, 50, 60, 70, 80, 90, 100, 150 };
const static std::string eloName[19] = { "Iron 1", "Iron 2", "Iron 3", "Bronze 1", "Bronze 2", "Bronze 3",
										"Silver 1", "Silver 2", "Silver 3", "Gold 1", "Gold 2", "Gold 3",
										"Platin 1", "Platin 2", "Platin 3", "Diamond 1", "Diamond 2",
										"Diamond 3", "Immortal" };
const static raylib::Color eloColor[19] = { GRAY, GRAY, GRAY, BROWN, BROWN, BROWN, LIGHTGRAY, LIGHTGRAY, LIGHTGRAY,
											GOLD, GOLD, GOLD, LIME, LIME, LIME, SKYBLUE, SKYBLUE, SKYBLUE,
											VIOLET };
struct Elo {
	int		points;
	int		rank;
	int		gain;
	int		trend;
	bool	change;

	JS_OBJ(points, rank);
};

#endif