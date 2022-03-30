/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:27:06 by khirsig           #+#    #+#             */
/*   Updated: 2022/03/30 13:23:51 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "../raylib-cpp/include/raylib-cpp.hpp"
# include "Circle.hpp"
# include "../config.hpp"

# define STANDARD 0
# define ICE 1
# define MIRROR_ICE 2
# define GROWTH 3
# define WARP 4

const static std::string modeText[] {
	"Mode: Standard", "Mode: Ice", "Mode: Mirror Ice",
	"Mode: Growth", "Mode: Warp"
};

class Player {
	public:
		Player();
		~Player();

		void			setupPlayer();
		void			movePlayerStandard();
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
		int				getPowerUpAmount() { return (this->_powerUpAmount); }
		int				getPowerUpHold() { return (this->_powerUpHold); }
		void			setPowerUpHold(int powerUpID) { this->_powerUpHold = powerUpID; }

		int				id;
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
		int				_powerUpAmount;
		int				_powerUpHold;
};


#endif