/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:30:01 by azabir            #+#    #+#             */
/*   Updated: 2022/10/07 12:47:05 by yagnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
#define CUB_H

# include <math.h>
# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define INIT_ANG 20
# define RO_SPEED 3
# define SPEED 15
# define COL_SPEED 2
# define UNIT 50
# define SCAL 0.2
# define MINI_UNIT (UNIT * SCAL)
# define RAD M_PI / 180
# define WIN_HIGHT 750
# define WIN_WIDTH 1000
# define FOV 60.0000
# define RAY_OFS (FOV / WIN_WIDTH)

typedef struct s_cords
{
	float	x;
	float	y;
}	t_cords;

typedef	struct s_ang
{
	float	value;
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
	float	ang_addj;
	float	step;
	int		wall_color;
	int		*tex;
	float	x_step;
	float	y_step;
	float	wall_hight;
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

typedef struct s_textures
{
	t_img			img;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
}	t_textures;

typedef struct s_color
{
	unsigned int	c;
	unsigned int	f;
	int				r;
	int				g;
	int				b;
}	t_color;

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
	t_textures	text;
	int			fd;
	t_player	player;
}	t_data;

int		check_file(char *path);
int		check_for_player(char c, int *count);
void	print_and_exit(char *str);
void	read_map(int fd, t_data *data);
void	check_for_end(t_map *map, int i, int j);
void	check_for_space(t_map *map, int i, int j);
void	check_top_bottom_tab(t_map *map, int i, int j, int len);
void	check_for_newline(char *str);
int		scean_init(t_data	*data);
t_ray	*rays_render(t_img *img, t_player player, t_map map);
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
void	player_update(t_player *player, float *ang, char **map);
void	map_render(t_img *img, char	**map);
void	bloc_draw(t_img *img, int x, int y, int color);
int		is_a_wall(t_map main_map,float x, float y);
void	draw_ray(t_img *img, t_ray ray, int color);
void	ray_casting(t_ray *ray, t_map map);
void	draw_wall(t_img *img, int index, float hight, int color);
int		is_in_win(float x, float y);
int		is_in_map(t_map map,float x, float y);
int		ft_strlen(char *str);
void	*mlx_png_file_to_image(void *mlx_ptr, char *filename, int *width, int *height);
t_ray	hor_ray_init(t_player *player, float ang, t_map map);

#endif