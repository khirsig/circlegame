/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Circle.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 10:42:22 by khirsig           #+#    #+#             */
/*   Updated: 2022/05/04 15:24:40 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CIRCLE_HPP
# define CIRCLE_HPP

# define UP 0
# define LEFT 1
# define DOWN 2
# define RIGHT 3

# include "../raylib-cpp/include/raylib-cpp.hpp"
# include "../config.hpp"

class Circle {
	public:
		Circle();
		~Circle();

		void			moveCircle();
		void			drawCircle();
		void			resetCircle();
		void			activateCircle();
		void			deactivateCircle();

		static int		getCircleAmount() { return (Circle::_circleAmount); }
		raylib::Vector2	getCirclePos();
		double			getCircleSize();
		void			updateSpeed();
		void			addMinSpeed(double minSpeed) { Circle::_modMinSpeed += minSpeed; }
		void			addMaxSpeed(double maxSpeed) { Circle::_modMaxSpeed += maxSpeed; }
		void			setMinSpeed(double minSpeed) { Circle::_modMinSpeed = minSpeed; }
		void			setMaxSpeed(double maxSpeed) { Circle::_modMaxSpeed = maxSpeed; }
		int				getIncreaseTime() { return (Circle::_increaseTime); }
		void			setIncreaseTime(int increaseTime) { Circle::_increaseTime = increaseTime; }
		void			setMoveDir(int moveDir) { Circle::_moveDir = moveDir; }

		void			setDirection(int spawnDir);
		raylib::Vector2	direction;
	private:
		static int		_circleAmount;
		raylib::Vector2	_pos;
		raylib::Color	_color;
		double			_size;
		double			_speed;
		int				_moveDir;
		bool			_active;
		static double	_modMinSpeed;
		static double	_modMaxSpeed;
		static int		_increaseTime;
};

float getRandomNumber(float min, float max);


#endif