/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <azabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:56:49 by azabir            #+#    #+#             */
/*   Updated: 2022/10/07 18:26:13 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"


void	map_render(t_img *img, char	**map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if(map[x][y] == '1')
				bloc_draw(img, y * MINI_UNIT, x * MINI_UNIT, 0X999900);
			else if (map[x][y] == '0')
				bloc_draw(img, y * MINI_UNIT, x * MINI_UNIT, 0X000000);
			y++;
		}
		x++;
	}
}

void	rays_render(t_img *img, t_player player, t_map map)
{
	float	ray_ang;
	int		ray_index;
	float	s;
	t_ray	v_ray;
	t_ray	h_ray;


	s = 60.0000 / WIN_WIDTH;
	ray_index = 0;
	ray_ang = -30;
	while (ray_ang <= 30)
	{
		h_ray = hor_ray_init(&player, ray_ang, map);
		v_ray = vert_ray_init(&player, ray_ang, map);
		if (h_ray.len > v_ray.len)
		{
			//draw_ray(img, v_ray, 0x3333FF);
			draw_wall(img, ray_index, v_ray.wall_hight, 0x3333FF);
		}
		else
		{
			//draw_ray(img, h_ray, 0x3333FF);
			draw_wall(img, ray_index, h_ray.wall_hight, 0x3333FF);
		}
		ray_index ++;
		ray_ang += s;
	}
	//fprintf(stderr, "s = %f\r", s);
}

void	player_render(t_img *img, t_player player, t_map map)
{
	int		i;
	float	x;
	float 	y;

	x = player.x;
	y = player.y;

	i = 0;
	while (i++ < 10)
	{
		x += player.dx;
		y += player.dy;
		my_pixel_put(img, (int)x, (int)y, 0XFFFFFF);
	}
}

int	rendering(t_data *data)
{
	t_img	img;
	
	mlx_clear_window(data->mlx, data->win.ptr);
	img.ptr =  mlx_new_image(data->mlx, WIN_WIDTH, WIN_HIGHT);
	img.addr = mlx_get_data_addr(img.ptr, &img.bit_per_pixel, &img.line_length,
				&img.endian);
	rays_render(&img, data->player, data->main_map);
	map_render(&img, data->main_map.map);
	player_render(&img, data->player, data->main_map);
	mlx_put_image_to_window(data->mlx, data->win.ptr, img.ptr, 0, 0);
	mlx_destroy_image(data->mlx , img.ptr);
	return (0);
}
