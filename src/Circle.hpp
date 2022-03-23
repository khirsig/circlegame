/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Circle.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 10:42:22 by khirsig           #+#    #+#             */
/*   Updated: 2022/03/22 15:16:12 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CIRCLE_HPP
# define CIRCLE_HPP

# define UP 0
# define LEFT 1
# define DOWN 2
# define RIGHT 3

# include "../raylib-cpp/include/raylib-cpp.hpp"

class Circle {
	public:
		Circle();
		~Circle();

		void			moveCircle(int screenWidth, int screenHeight);
		void			drawCircle();
		void			resetCircle(int screenWidth, int screenHeight);
		void			activateCircle();
		void			deactivateCircle();
		static int		getCircleAmount() { return (Circle::_circleAmount); }
		raylib::Vector2 getCirclePos();
		double			getCircleSize();
	private:
		static int		_circleAmount;
		raylib::Vector2	_pos;
		raylib::Color	_color;
		double			_size;
		double			_speed;
		int				_moveDir;
		bool			_active;
};


#endif