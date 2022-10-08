/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <azabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:30:01 by azabir            #+#    #+#             */
/*   Updated: 2022/10/07 18:11:25 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
#define CUB_H

# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include "../libs/libft.h"

#define INIT_ANG 45
#define RO_SPEED 4
#define SPEED 10
#define	COL_SPEED 0.5
#define UNIT 50
#define	SCAL 1
#define MINI_UNIT (UNIT * SCAL)
#define	RAD M_PI / 180
#define WIN_HIGHT 550
#define WIN_WIDTH 1600
#define	FOV 60

typedef struct s_cords
{
	float	x;
	float	y;
}	t_cords;

typedef	struct s_ang
{
	int		value;
	int		to_right;
	int		to_up;
	int		x_ofs;
	int		y_ofs;
}	t_ang;

typedef struct s_ray
{
	float	len;
	t_cords	start;
	t_cords	end;
	t_ang	ang;
	float	ang_tg;
	float	dx;
	float	dy;
	float	step;
	float	x_step;
	float	y_step;
	float	Wall_hight;
}	t_ray;

typedef	struct s_img
{
	int		x;
	int 	y;
	char	*addr;
	int		bit_per_pixel;
	void	*ptr;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_player
{
	float		x;
	float		y;
	int			can_move_f;
	int			can_move_b;
	float		dx;
	float		dy;
	t_ang		ang;
}	t_player;

typedef	struct s_map
{
	char		**map;
	int			x_len;
	int			y_len;
	t_player	player;
}	t_map;

typedef	struct s_window
{
	int		hight;
	int		width;
	void	*ptr;
}	t_window;

typedef	struct s_data
{
	t_map		main_map;
	void		*mlx;
	t_window	win;
	t_img		img;
	int			fd;
	t_player	player;
}	t_data;


int		scean_init(t_data	*data);
t_img	*img_init(t_data *data);
void	ray_init(t_player *player, t_ray *ray, float ang);
t_ray	vert_ray_init(t_player *player, float ang, t_map map);
int		key_hook(int keycode, t_data *data);
void	map_check(t_data *data);
void	dda_algo(t_img *img, float x0, float y0, float x1, float y1, int color);
int		rendering(t_data *data);
void	add_collision_trans(t_player *player, char **map);
void	ang_update(t_ang *ang, float value);
void	my_pixel_put(t_img *img, int x, int y, int color);
void	player_update(t_player *player, int *ang, char **map);
void	map_render(t_img *img, char	**map);
void	bloc_draw(t_img *img, int x, int y, int color);
int		is_a_wall(t_map main_map,float x, float y);
void	draw_ray(t_img *img, t_ray ray, int color);
void	ray_casting(t_ray *ray, t_map map);
int		is_in_win(float x, float y);
int		is_in_map(t_map map,float x, float y);
t_ray	hor_ray_init(t_player *player, float ang, t_map map);

#endif
