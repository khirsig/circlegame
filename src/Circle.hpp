/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Circle.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 10:42:22 by khirsig           #+#    #+#             */
/*   Updated: 2022/03/18 14:50:22 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CIRCLE_HPP
# define CIRCLE_HPP

# define UP 0
# define LEFT 1
# define DOWN 2
# define RIGHT 3

# include "../raylib-cpp/include/raylib-cpp.hpp"
// # include "circlegame.hpp"

class Circle {
	public:
		Circle();
		Circle(int screenWidth, int screenHeight);
		~Circle();
		void			moveCircle(int screenWidth, int screenHeight);
		void			drawCircle();
		void			resetCircle(int screenWidth, int screenHeight);
		static int		getCircleAmount() { return (Circle::_circleAmount); }
	private:
		static int		_circleAmount;
		raylib::Vector2	_pos;
		raylib::Color	_color;
		double			_size;
		double			_speed;
		int				_moveDir;
};


#endif