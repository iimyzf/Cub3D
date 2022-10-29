/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <azabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:30:01 by azabir            #+#    #+#             */
/*   Updated: 2022/10/28 23:00:48 by yagnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <math.h>
# include "../minilibx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define INIT_ANG 0.1
# define RO_SPEED 3
# define SPEED 10
# define COL_SPEED 5
# define UNIT 50
# define SCAL 0.2
# define WIN_HIGHT 720
# define WIN_WIDTH 1280
# define FOV 60.0000

typedef struct s_norm
{
	int		i;
	int		j;
	char	*tmp;
	char	**map;
}	t_norm;

typedef struct s_cords
{
	float	x;
	float	y;
}	t_cords;

typedef struct s_ang
{
	float	value;
	int		to_right;
	int		to_up;
	int		x_ofs;
	int		y_ofs;
}	t_ang;

typedef struct s_img
{
	char	*addr;
	void	*ptr;
	int		x;
	int		y;
	int		bit_per_pixel;
	int		line_length;
	int		endian;
	int		c_clr;
	int		f_clr;
}	t_img;

typedef struct s_player
{
	float		x;
	float		y;
	float		dx;
	float		dy;
	int			can_move_f;
	int			can_move_b;
	int			x_slid;
	int			y_slid;
	char		type;
	t_ang		ang;
}	t_player;

typedef struct s_color
{
	unsigned int	c;
	unsigned int	f;
	int				r;
	int				g;
	int				b;
	int				clr;
}	t_color;

typedef struct s_texture
{
	int				**colors;
	t_img			img;
	t_color			the_color;
}	t_texture;

typedef struct s_textures
{
	int				**colors;
	t_img			img;
	t_texture		no;
	t_texture		so;
	t_texture		ea;
	t_texture		we;
	t_color			the_color;
}	t_textures;

typedef struct s_ray
{
	t_cords		start;
	t_cords		end;
	t_ang		ang;
	t_texture	text;
	float		len;
	float		ang_tg;
	float		dx;
	float		dy;
	float		ang_addj;
	float		step;
	float		x_step;
	float		y_step;
	int			wall_color;
	int			color_index;
	int			wall_start;
	int			wall_end;
	int			is_vert;
	int			wall_hight;
}	t_ray;

typedef struct s_map
{
	char		**map;
	int			x_len;
	int			y_len;
	t_textures	text;
	t_player	player;
}	t_map;

typedef struct s_window
{
	void	*ptr;
	int		high;
	int		width;
}	t_window;

typedef struct s_data
{
	void		*mlx;
	int			fd;
	int			ch;
	t_img		img;
	t_map		main_map;
	t_color		color;
	t_window	win;
	t_player	player;
	t_textures	text;
	t_ang		ang;
}	t_data;

unsigned int	rgb_to_int(int r, int g, int b);
unsigned int	get_color(char *str, t_data *data);
int				check_file(char *path);
int				ft_exit(t_data *data);
int				get_colors(t_textures text, int x, int y);
int				can_move_side(t_player *player, t_map map, int to_right);
int				check_for_player(char c, int *count);
int				check_for_fc(char c, int *count);
int				is_a_wall(t_map main_map, float x, float y);
int				ft_isplayer(int c);
int				is_in_win(float x, float y);
int				is_in_map(t_map map, float x, float y);
int				get_colors2(t_texture text, int x, int y);
int				ft_strlen(char *str);
int				rendering(t_data *data);
int				mouse_hook(int x, int y, t_data *data);
int				hook(t_data *data);
int				key_hook(int keycode, t_data *data);
char			**get_the_map(char **map);
char			**my_split(char const *s, char c);
char			*get_str(char *str);
char			*get_next_line(int fd);
char			**get_first_six_lines(char **map);
char			*get_next_line(int fd);
char			**read_map(char *str);
char			**get_the_map(char **file);
char			*trimming(char *str);
char			*get_str(char *str);
char			**read_map(char *arg);
void			print_and_exit(char *str);
void			get_element(char **map, t_data *data);
void			check_for_end(char **map, int i, int j);
void			check_for_space(char **map, int i, int j);
void			check_udrl(char **map, int i, int j, int len);
void			check_for_newline(char *str);
void			scean_init(t_data	*data);
void			ray_init(t_player *player, t_ray *ray, float ang);
void			add_collision_trans(t_player *player, char **map, int fact);
void			ang_update(t_ang *ang, float value);
void			my_pixel_put(t_img *img, int x, int y, int color);
void			player_update(t_player *player, float *ang, char **map);
void			map_render(t_img *img, char	**map);
void			bloc_draw(t_img *img, int x, int y, int color);
void			draw_ray(t_img *img, t_ray ray, int color);
void			ray_casting(t_ray *ray, t_map map);
void			ray_add_wall_data(t_ray *ray, t_map map);
void			fill_colors2(t_texture *text);
void			draw_wall(t_img *img, int index, t_ray ray, t_texture text);
void			map_checking(char **map, t_data *data);
void			free_array(char **arr);
void			*mlx_png_file_to_image(void *mlx_ptr, char *filename,
					int *width, int *height);
t_ray			*rays_render(t_img *img, t_player player, t_map map);
t_ray			vert_ray_init(t_player *player, float ang, t_map map);
t_ray			hor_ray_init(t_player *player, float ang, t_map map);
t_img			img_init(t_data *data);

#endif