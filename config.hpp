/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:00:34 by khirsig           #+#    #+#             */
/*   Updated: 2022/04/24 18:08:44 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_HPP
# define CONFIG_HPP

//	Define screen ratio. Has to be 16x9. As example: 1920x1080
# define SCREEN_WIDTH 1408
# define SCREEN_HEIGHT 792

//	Define screen FPS
# define SCREEN_FPS 123

//	Define player count
# define PLAYER_COUNT 1

extern int		screenWidth;
extern int		screenHeight;
extern int		currentFPS;
extern int		currentTime;
extern int		startTime;

#endif