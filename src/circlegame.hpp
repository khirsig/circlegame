/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circlegame.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 09:45:29 by khirsig           #+#    #+#             */
/*   Updated: 2022/04/27 15:15:15 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CIRCLEGAME_HPP
# define CIRCLEGAME_HPP

# include <string>
# include <iostream>
# include <random>
# include "../include/json_struct.h"
# include "../raylib-cpp/include/raylib-cpp.hpp"
# include "../config.hpp"
# include "Circle.hpp"
# include "Player.hpp"
# include "PowerUp.hpp"
# include "Interface.hpp"
# include "Elo.hpp"
# include "User.hpp"

# define PRE_START 0
# define START_SCREEN 1
# define LOADING_SCREEN 2
# define IN_GAME 3
# define ELO_SCREEN 4
# define GAME_OVER 5

const static std::string menuText[] {
	"CIRCLEGAME", "Press Enter to Play the Game!", "alpha v0.3",
	"GAMEOVER", "Press Enter to see Elo changes!"
};

const static int	menuTextSize[] {
	SCREEN_HEIGHT / 14, SCREEN_HEIGHT / 28, SCREEN_HEIGHT / 36,
	SCREEN_HEIGHT / 16, SCREEN_HEIGHT / 28
};

struct Data {
	raylib::Window		window{SCREEN_WIDTH, SCREEN_HEIGHT, "circlegame"};
	int					screenFPS = SCREEN_FPS;
	int					gameMode = PRE_START;
	bool				gameover = 0;
	const static int	circleAmount = 2;
	Circle 				circle[circleAmount];
	const static int	playerAmount = PLAYER_COUNT;
	Player				player[playerAmount];
	const static int	powerUpAmount = 3;
	PowerUp				powerUp[powerUpAmount];
	int					startTime;
	int					currentTime;
	int					modeTime;
	Interface			interface;
	Elo					elo;
	User				user;
};

void	startScreen(Data &data);
void	loadingScreen(Data &data);
void	ingame(Data &data);
void	drawCircle(Data &data);
void	drawPlayer(Data &data);
void	movePlayer(Data &data);
float	getRandomNumber(float min, float max);
void    setStartTime(Data &data);
void    setCurrentTime(Data &data);
void    newRound(Data &data);

void	modeGUI(Data &data);
void	timeGUI(Data &data);
void	powerUpGUI(Data &data);
void	eloGUI(Data &data);

void	changeMode(Data &data);
void	setFPS(Data &data);

void	powerUpSpawn(Data &data);
void	powerUpDraw(Data &data);
void    takePowerUp(Data &data);
void    usePowerUp(Data &data);

void    increaseCircleSpeed(Data &data);

void	loadResources(Data &data);

void	calcElo(Data &data);
void	eloScreen(Data &data);
void    loginServerRequest(Data &data);
void    setEloServer(Data &data);

#endif