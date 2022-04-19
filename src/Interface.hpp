/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Interface.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:43:53 by khirsig           #+#    #+#             */
/*   Updated: 2022/04/19 16:15:52 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERFACE_HPP
# define INTERFACE_HPP

# include "../raylib-cpp/include/raylib-cpp.hpp"
# include <vector>

class Interface {
	public:
		Interface();
		~Interface();

		std::vector<raylib::Texture>	powerupImg;
};

#endif