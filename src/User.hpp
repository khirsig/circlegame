/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:31:56 by khirsig           #+#    #+#             */
/*   Updated: 2022/05/16 13:53:32 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Elo.hpp"
# include "../include/json_struct.h"
// # include <json_struct.h>

struct User {
	std::string	username;
	std::string	password;
	Elo			elo;
	bool		loggedIn = false;

	JS_OBJ(username, password, elo);
};
