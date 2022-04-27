/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:27:06 by khirsig           #+#    #+#             */
/*   Updated: 2022/04/27 15:22:27 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "../raylib-cpp/include/raylib-cpp.hpp"
# include "Circle.hpp"
# include "../config.hpp"
# include <vector>

# define STANDARD 0
# define ICE 1
# define MIRROR_ICE 2
# define MIRROR
# define GROWTH 4

const static std::string modeText[] {
	"Mode: Standard", "Mode: Ice", "Mode: Mirror Ice",
	"Mode: Mirror", "Mode: Growth"
};

class Player {
	public:
		Player();
		~Player();

		void			setupPlayer();
		void			movePlayerStandard();
		void			movePlayerMirror();
		void			movePlayerIce();
		void			movePlayerMirrorIce();
		void			drawPlayer();
		bool			collisionPlayer(Circle circle);
		void			setMoveDir(int input);
		void			modeExec();
		void			growthMode();

		int				getSize() { return (this->_size); }
		int				getMode() { return (this->_mode); }
		void			setMode(int id);
		raylib::Color	getColor() { return (this->_color); }
		raylib::Color	getPlayerColor() { return (this->_playerColor); }
		raylib::Vector2	getPos() { return (this->_pos); }
		int				getPowerUpHold() { return (this->_powerUpHold); }
		void			setPowerUpHold(int powerUpID) { this->_powerUpHold = powerUpID; }
		int				getShieldTimer() { return (this->_shieldTimer); }
		void			setShieldTimer(int endTime) { this->_shieldTimer = endTime; }
		bool			getActiveShield() { return (this->_activeShield); }
		void			setActiveShield(bool status) { this->_activeShield = status; }

		int										id;
		raylib::Texture							shieldImg = raylib::Texture("./resources/shield.png");
		std::vector<raylib::Texture>			modeImg;
	private:
		raylib::Vector2	_pos;
		raylib::Color	_color;
		raylib::Color	_playerColor;
		double			_size;
		double			_speed;
		int				_mode;
		int				_moveDir;
		int				_growthDir;
		double			_growthBase;
		int				_powerUpHold;
		int				_shieldTimer;
		bool			_activeShield;

};


#endif