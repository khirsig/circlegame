/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circlegame.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 09:45:29 by khirsig           #+#    #+#             */
/*   Updated: 2022/03/23 12:19:50 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CIRCLEGAME_HPP
# define CIRCLEGAME_HPP

# include <string>
# include <iostream>
# include <random>
# include "../raylib-cpp/include/raylib-cpp.hpp"
# include "../config.hpp"
# include "Circle.hpp"
# include "Player.hpp"

# define START_SCREEN 0
# define LOADING_SCREEN 1
# define IN_GAME 2
# define GAME_OVER 3

const static std::string menuText[] {
	"CIRCLEGAME", "Press Enter to Play the Game!", "alpha v0.1",
	"GAMEOVER", "Press Enter to return to Mainmenu!"
};

const static int	menuTextSize[] {
	SCREEN_HEIGHT / 14, SCREEN_HEIGHT / 28, SCREEN_HEIGHT / 36,
	SCREEN_HEIGHT / 16, SCREEN_HEIGHT / 28
};

struct Data {
	raylib::Window		window{SCREEN_WIDTH, SCREEN_HEIGHT, "circlegame"};
	int					screenWidth = SCREEN_WIDTH;
	int					screenHeight = SCREEN_HEIGHT;
	int					screenFPS = SCREEN_FPS;
	int					gameMode = START_SCREEN;
	bool				gameover = 0;
	const static int	circleAmount = 5;
	Circle 				circle[circleAmount];
	Player				player;
};

void	startScreen(Data &data);
void	loadingScreen(Data &data);
void	ingame(Data &data);
void	drawCircle(Data &data);
void	drawPlayer(Data &data);
float	getRandomNumber(float min, float max);

void	modeGUI(Data &data);


#endif