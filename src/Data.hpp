/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:17:29 by khirsig           #+#    #+#             */
/*   Updated: 2022/03/16 10:33:01 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# define START_SCREEN 0
# define LOADING_SCREEN 1
# define IN_GAME 2
# define GAME_OVER 3

# include "../config.hpp"
# include "../raylib-cpp/include/raylib-cpp.hpp"

class Data {
	public:
		int				getGameMode();
		raylib::Window	&getWindow();
		void			setupWindow();
		void			setGameMode(int newGameMode);
	private:
		raylib::Window _window;
		int	_screenWidth = SCREEN_WIDTH;
		int	_screenHeight = SCREEN_HEIGHT;
		int	_screenFPS = SCREEN_FPS;
		int	_gameMode = START_SCREEN;
};

#endif