/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:30:01 by azabir            #+#    #+#             */
/*   Updated: 2022/10/19 21:17:37 by yagnaou          ###   ########.fr       */
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

# define INIT_ANG 0
# define RO_SPEED 4
# define SPEED 30
# define COL_SPEED 2
# define UNIT 50
# define SCAL 0.2
# define MINI_UNIT (UNIT * SCAL)
# define RAD M_PI / 180
# define WIN_HIGHT 750
# define WIN_WIDTH 1100
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
}	t_ang;

typedef struct s_ray
{
	float	len;
	t_cords	start;
	t_cords	end;
	t_ang	ang;
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

typedef	struct s_map
{
	char	**map;
	int		x_len;
	int		y_len;
}	t_map;

typedef struct s_textures
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
}	t_textures;

typedef struct s_color
{
	unsigned int	clr;
	unsigned int	c;
	unsigned int	f;
	int				r;
	int				g;
	int				b;
}	t_color;

typedef struct s_player
{
	float		x;
	float		y;
	float		dx;
	float		dy;
	char		type;
	t_ang		ang;
}	t_player;

typedef	struct s_window
{
	int		height;
	int		width;
	void	*ptr;
}	t_window;

typedef	struct s_data
{
	t_map		main_map;
	void		*mlx;
	t_window	*win;
	t_img		img;
	int			fd;
	t_player	player;
	t_color		color;
}	t_data;

int		check_file(char *path);
int		check_for_player(char c, int *count);
char	*get_str(char *str);
char	*get_next_line(int fd);
void	print_and_exit(char *str);
char	**read_map(char *arg);
void	get_element(char *map, t_data *data);
void	check_for_end(char **map, int i, int j);
void	check_for_space(char **map, int i, int j);
void	check_udrl(char **map, int i, int j, int len);
void	check_for_newline(char *str);
void	map_checking(char **map, t_data *data);
char	**get_the_map(char **map);
char	**get_first_six_lines(char **map);

#endif