/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circlegame.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 09:45:29 by khirsig           #+#    #+#             */
/*   Updated: 2022/05/04 11:40:48 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CIRCLEGAME_HPP
# define CIRCLEGAME_HPP


# include <string>
# include <iostream>
# include <fstream>
# include <sstream>
# include <random>
# include <tgmath.h>
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
# define OPTIONS 5
# define GAME_OVER 6

# define NOGAME -1
# define NORMALGAME 0
# define RANKEDGAME 1
# define SPLITSCREEN 2

struct Data {
	raylib::Window		window{screenWidth, screenHeight, "circlegame"};
	int					screenFPS = SCREEN_FPS;
	int					gameMode = PRE_START;
	int					gameType = NOGAME;
	bool				gameover = 0;
	const static int	circleAmount = 4;
	Circle 				circle[circleAmount];
	int					playerAmount = 1;
	Player				player[2];
	const static int	powerUpAmount = 3;
	PowerUp				powerUp[powerUpAmount];
	int					dyingPlayer = 0;
	int					startTime;
	int					currentTime;
	int					modeTime;
	int					difficulty;
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
void	impulseHit(Data &data);
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
void    loginHandler(Data &data);

void			optionsScreen(Data &data);
bool			drawMenuText(Data &data, int id, const char *text, int posX, int posY, int textSize);
void			saveSettings(Data &data);
void			loadSettings(Data &data);
void			updateWindow(Data &data);

#endif