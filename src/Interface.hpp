/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Interface.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:43:53 by khirsig           #+#    #+#             */
/*   Updated: 2022/04/29 16:07:56 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERFACE_HPP
# define INTERFACE_HPP

# include "../raylib-cpp/include/raylib-cpp.hpp"
# include <vector>
# include "../config.hpp"

const static std::string	mainMenuText[] { "Normal Game (1P)", "Ranked Game (1P)", "Split Screen (2P)", "Options", "Exit" };

const static std::string	optionsText[] { "Return", "Resolution" };

const static std::string	menuText[] {
	"CIRCLEGAME", "Press Enter to Play the Game!", "alpha v0.5",
	"GAMEOVER", "Press Enter to see Elo changes!", "Press Enter to return to Main Menu!",
	"BLUE WON", "RED WON"
};

static std::vector<int>	menuTextSize = {
	screenHeight / 8, screenHeight / 24, screenHeight / 36,
	screenHeight / 16, screenHeight / 28
};

class Interface {
	public:
		Interface();
		~Interface();

		std::vector<raylib::Texture>	powerupImg;
		std::vector<raylib::Texture>	pubImg;
		std::vector<raylib::Texture>	eloImg;

		bool		resButton[2] = { false, false };
		bool		*onButton = nullptr;
		std::string	widthStr = std::to_string(screenWidth);
		std::string	heightStr = std::to_string(screenHeight);
};

#endif