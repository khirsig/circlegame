/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:28:38 by khirsig           #+#    #+#             */
/*   Updated: 2022/03/22 13:30:50 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circlegame.hpp"

float getRandomNumber(float min, float max)
{
    static std::default_random_engine engine;
    static std::uniform_real_distribution<> ret(min, max);
    return ret(engine);
}