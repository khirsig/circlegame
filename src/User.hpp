/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:31:56 by khirsig           #+#    #+#             */
/*   Updated: 2022/04/27 15:07:09 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USER_HPP
# define USER_HPP

# include "Elo.hpp"
# include "../include/json_struct.h"
// # include <json_struct.h>

struct User {
	std::string	username;
	std::string	password;
	Elo			elo;

	JS_OBJ(username, password, elo);
};



#endif
