/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:00:34 by khirsig           #+#    #+#             */
/*   Updated: 2022/04/29 16:24:04 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_HPP
# define CONFIG_HPP

//	Define screen ratio. Has to be 16x9. As example: 1920x1080


//	Define screen FPS
# define SCREEN_FPS 123

extern int		screenWidth;
extern int		screenHeight;
extern int		currentFPS;
extern int		currentTime;
extern int		startTime;

#endif