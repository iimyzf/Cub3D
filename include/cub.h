/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <azabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:30:01 by azabir            #+#    #+#             */
/*   Updated: 2022/10/04 15:59:00 by azabir           ###   ########.fr       */
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

typedef struct s_player
{
	float		x;
	float		y;
	float		dx;
	float		dy;
	t_ang		ang;
}	t_player;

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
	t_window	*win;
	t_img		img;
	int			fd;
	t_player	player;
}	t_data;


