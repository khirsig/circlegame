/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_gui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:47:32 by khirsig           #+#    #+#             */
/*   Updated: 2021/10/18 14:36:48 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/circlegame.h"

void	text_gui(t_data *data)
{
	char *temp;

	if (data->special_mode == NORMAL)
		DrawText("Mode: Standard", 320, 10, 20, MAROON);
	if (data->special_mode == REVERSE)
		DrawText("Mode: Reverse", 320, 10, 20, LIME);
	if (data->special_mode == BIG)
		DrawText("Mode: Big", 340, 10, 20, MAROON);
	if (data->special_mode == ICE)
		DrawText("Mode: Ice", 340, 10, 20, SKYBLUE);
	if (data->special_mode == MIRROR_ICE)
		DrawText("Mode: Mirror Ice", 320, 10, 20, MIRROR_ICE_GREEN);
	if (data->special_mode == GROWTH)
		DrawText("Mode: Growth", 320, 10, 20, GROWTH_PURPLE);
	if (data->special_mode == SPEED)
		DrawText("Mode: Speed", 320, 10, 20, BLUE);
	temp = ft_itoa(GetTime());
	if (GetTime() != data->seconds_run)
		data->seconds_run = GetTime();
	DrawText(temp, 10, 30, 20, BLUE);
	free(temp);
	temp = ft_itoa(GetFPS());
	DrawText(temp, 10, 10, 20, DARKGREEN);
	free(temp);
	temp = ft_itoa(data->hiscore);
	DrawText("Hiscore:", 10, data->screen_height - 30, 20, MAROON);
	DrawText(temp, 100, data->screen_height - 30, 20, MAROON);
	free(temp);
	return ;
}