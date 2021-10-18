/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circlegame.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:18:29 by khirsig           #+#    #+#             */
/*   Updated: 2021/10/18 13:39:05 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIGAME_H
# define MINIGAME_H

# define TRUE 1
# define FALSE 0
# define ERROR -1

# define NORMAL 0
# define REVERSE 1
# define BIG 2
# define ICE 3
# define MIRROR_ICE 4

# define NONE -1
# define LEFT 0
# define UP 1
# define RIGHT 2
# define DOWN 3
# define LEFT_UP 4
# define RIGHT_UP 5
# define RIGHT_DOWN 6
# define LEFT_DOWN 7

# define GAMEOVER 0
# define GAME 1

/*
** -----------------------------------------------------------------------------
** Includes
*/
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include "../libs/libft/libft.h"
# include "/opt/homebrew/Cellar/raylib/3.7.0/include/raylib.h"

/*
** -----------------------------------------------------------------------------
** Structs and typedef.
*/
typedef enum {
	STORAGE_POSITION_HISCORE	= 1
} StorageData;

typedef struct s_enemy
{
	Vector2	position;
	Color	color;
	float	size;
	float	speed;
	int		move_direction;
}				t_enemy;

typedef struct s_data {
	Vector2	ball_position;
	Color	ball_color;
	t_enemy	enemy[10];
	float	enemy_speed;
	float	ball_size;
	int		hiscore;
	int		slide_amount;
	int		slide_direction;
	int		is_sliding;
	int		seconds_run;
	int		last_modeswap;
	int		screen_height;
	int		screen_width;
	int		special_mode;
	int 	total_enemies;
	int 	current_enemies;
}				t_data;

/*
** -----------------------------------------------------------------------------
** Function prototypes
*/
void	move_character(t_data *data);
int		init_data(t_data *data);
void	special_modes(t_data *data);
void	text_gui(t_data *data);
void	enemies(t_data *data);
int		player_collision(t_data *data);
void	enemy_collision(t_data *data);
void	ice_slide(t_data *data);
void	mirror_slide(t_data *data);

#endif
