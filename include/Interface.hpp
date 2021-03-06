/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Interface.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:43:53 by khirsig           #+#    #+#             */
/*   Updated: 2022/06/14 14:39:42 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "../extern/raylib-cpp/include/raylib-cpp.hpp"
# include <vector>
# include "config.hpp"

const static std::string	mainMenuText[] { "Normal Game (1P)", "Ranked Game (1P)", "Split Screen (2P)", "Options", "Exit" };

const static std::string	optionsText[] { "Return", "Resolution", "Difficulty", "Circle Amount" };

const static std::string	menuText[] {
	"CIRCLEGAME", "Press Enter to Play the Game!", "alpha v0.5",
	"GAMEOVER", "Press Enter to see Elo changes!", "Press Enter to return to Main Menu!",
	"BLUE WON", "RED WON"
};

const static std::string	tutorialText[] {
	"How to Play", "This is you:", "Move your player with"

};

const static std::string	loadingText[] {
	"Loading Powerup Textures...", "Loading Player 1 Mode Textures...", "Loading Player 2 Mode Textures...",
	"Loading Misc Textures...", "Loading Elo Images..."
};

extern raylib::Color	backgroundColor;
extern bool				darkMode;

extern std::vector<int>	menuTextSize;

class Interface {
	public:
		Interface();
		~Interface();

		std::vector<raylib::Texture>	powerupImg;
		std::vector<raylib::Texture>	pubImg;
		std::vector<raylib::Texture>	eloImg;

		bool		resButton[2] = { false, false };
		bool		difButton = false;
		bool		circAmtButton = false;
		bool		*onButton = nullptr;
		int			mainMenuButton = -1;

		raylib::Vector2 difCircPos;
		raylib::Vector2 circAmtCircPos;
		std::string	widthStr = std::to_string(screenWidth);
		std::string	heightStr = std::to_string(screenHeight);
};
