/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elo.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 17:12:57 by khirsig           #+#    #+#             */
/*   Updated: 2022/04/24 18:19:26 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELO_HPP
# define ELO_HPP

# define IRON1 0
# define IRON2 1
# define IRON3 2
# define BRONZE1 3
# define BRONZE2 4
# define BRONZE3 5
# define SILVER1 6
# define SILVER2 7
# define SILVER3 8
# define GOLD1 9
# define GOLD2 10
# define GOLD3 11
# define PLAT1 12
# define PLAT2 13
# define PLAT3 14
# define DIAMOND1 15
# define DIAMOND2 16
# define DIAMOND3 17
# define IMMORTAL1 18
# define IMMORTAL2 19
# define IMMORTAL3 20
# define RADIANT 21

const static int eloThreshold[22] = { 0, 3, 5, 10, 12, 15, 20, 25, 30, 35,
									40, 45, 50, 60, 70, 80, 90, 100, 110,
									120, 130, 150 };
const static std::string eloName[22] = { "Iron 1", "Iron 2", "Iron 3", "Bronze 1", "Bronze 2", "Bronze 3",
										"Silver 1", "Silver 2", "Silver 3", "Gold 1", "Gold 2", "Gold 3",
										"Platin 1", "Platin 2", "Platin 3", "Diamond 1", "Diamond 2",
										"Diamond 3", "Immortal 1", "Immortal 2", "Immortal 3", "Radiant" };
const static raylib::Color eloColor[22] = { GRAY, GRAY, GRAY, BROWN, BROWN, BROWN, LIGHTGRAY, LIGHTGRAY, LIGHTGRAY,
											GOLD, GOLD, GOLD, LIME, LIME, LIME, SKYBLUE, SKYBLUE, SKYBLUE,
											VIOLET, VIOLET, VIOLET, ORANGE };
struct Elo {
	int	points;
	int	rank;
	int	gain;
};

#endif