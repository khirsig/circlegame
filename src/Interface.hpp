/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Interface.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:43:53 by khirsig           #+#    #+#             */
/*   Updated: 2022/04/07 16:33:33 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERFACE_HPP
# define INTERFACE_HPP

# include "../raylib-cpp/include/raylib-cpp.hpp"

class Interface {
	public:
		Interface();
		~Interface();

		raylib::Texture		powerupImg[1] = { raylib::Texture("./resources/powerup00.png") };
};

#endif