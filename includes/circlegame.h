/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circlegame.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjensen <tjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:18:29 by khirsig           #+#    #+#             */
/*   Updated: 2022/02/15 13:54:47 by tjensen          ###   ########.fr       */
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
# define GROWTH 5
# define SPEED 6
# define SLOW 7
# define WARP 8

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

# define ENEMYGRAY1 CLITERAL(Color){ 70, 70, 70, 255 }
# define ENEMYGRAY2 CLITERAL(Color){ 80, 80, 80, 255 }
# define ENEMYGRAY3 CLITERAL(Color){ 90, 90, 90, 255 }
# define ENEMYGRAY4 CLITERAL(Color){ 110, 110, 110, 255 }
# define ENEMYGRAY5 CLITERAL(Color){ 130, 130, 130, 255 }
# define MIRROR_ICE_GREEN CLITERAL(Color){ 0, 117, 117, 255 }
# define GROWTH_PURPLE CLITERAL(Color){ 100, 22, 255, 255 }

/*
** -----------------------------------------------------------------------------
** Includes
*/
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include "../libs/libft/libft.h"
# include "raylib.h"

/*
** -----------------------------------------------------------------------------
** Structs and typedef.
*/
typedef enum {
	STORAGE_POSITION_HISCORE	= 1
} StorageData;

typedef struct s_circle
{
	Vector2	position;
	Color	color;
	float	size;
	float	speed;
	int		move_direction;
}				t_circle;

typedef struct s_triangle
{
	Vector2	v1;
	Vector2 v2;
	Vector2 v3;
	Color	color;
	float	speed;
	float	speed_max;
	int		move_direction;
	int		times_moved;
	int		alive;
}				t_triangle;

typedef struct s_player
{
	Vector2	position;
	Color	color;
	float	size;
	float	speed;
	float	growth_min;
	float	growth_max;
	int		growth_direction;
	int		slide_amount;
	int		slide_direction;
	int		warp_power;
	int		warp_direction;
	int		is_sliding;
	int		tp_amount;
}				t_player;

typedef struct s_data {
	t_circle	circle[10];
	t_triangle	triangle;
	t_player 	player;
	int			hiscore;
	int			seconds_run;
	int			last_modeswap;
	int			screen_height;
	int			screen_width;
	int			special_mode;
	int 		total_circles;
	int 		current_circles;
}				t_data;

/*
** -----------------------------------------------------------------------------
** Function prototypes
*/
void	move_character(t_data *data);
int		init_data(t_data *data);
void	special_modes(t_data *data);
void	text_gui(t_data *data);
void 	player(t_data *data);
void	circles(t_data *data);
int		player_collision(t_data *data);
void	circle_collision(t_data *data);
void	ice_slide(t_data *data);
void	mirror_slide(t_data *data);
void	triangles(t_data *data);
void	warp_movement(t_data *data);

#endif
