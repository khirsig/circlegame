/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_gui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:47:32 by khirsig           #+#    #+#             */
/*   Updated: 2022/02/16 11:26:18 by khirsig          ###   ########.fr       */
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
	if (data->special_mode == SLOW)
		DrawText("Mode: Slow", 320, 10, 20, BROWN);
	if (data->special_mode == WARP)
		DrawText("Mode: Warp", 320, 10, 20, ORANGE);
	temp = ft_itoa(data->hiscore);
	DrawText("Hiscore:", data->screen_width - 130, data->screen_height - 30, 20, MAROON);
	DrawText(temp, data->screen_width - 40, data->screen_height - 30, 20, MAROON);
	temp = ft_itoa(data->current_run);
	DrawText("Score:", 10, data->screen_height - 30, 20, BLUE);
	DrawText(temp, 80, data->screen_height - 30, 20, BLUE);
	free(temp);
	return ;
}