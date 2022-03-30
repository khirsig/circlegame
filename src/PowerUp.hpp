/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerUp.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 09:41:38 by khirsig           #+#    #+#             */
/*   Updated: 2022/03/30 13:49:24 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POWERUP_HPP
# define POWERUP_HPP

# define DISABLED -1
# define SPAWNED 0
# define HOLDBYPLAYER 1
# define ACTIVATED 2
# define DESPAWNING 3
# define DESPAWNED 4

# define NONE -1
# define SKIPMODE 0
# define SHIELD 1

# include "../raylib-cpp/include/raylib-cpp.hpp"
# include "../config.hpp"
# include <iostream>

class PowerUp {
	public:
		PowerUp();
		~PowerUp() { }

		void	resetPowerUp();
		void	drawPowerUp();
		void	takePowerUp();
		void	activatePowerUp();
		void	passivePowerUp();

		int				getState() { return (this->_state); }
		void			setState(int newState) { this->_state = newState; }
		int				getSpawnTime() { return (this->_spawnTime); }
		void			setSpawnTime(int currentTime) { this->_spawnTime = currentTime; }
		int				getNextSpawnTime() { return (this->_nextSpawnTime); }
		void			setNextSpawnTime(int nextSpawn) { this->_nextSpawnTime = nextSpawn; }
		raylib::Vector2	getPos() { return (this->_pos); }
		int				getSize() { return (this->_sizeCurrent); }
		int				getID() { return (this->_id); }

	private:
		int					_id;
		int					_state;
		int					_maxTime;
		int					_activeTime;
		int					_spawnTime;
		int					_nextSpawnTime;
		raylib::Vector2		_pos;
		double				_sizeEnd;
		double				_sizeCurrent;
};

#endif
