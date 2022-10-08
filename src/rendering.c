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
				bloc_draw(img, y * MINI_UNIT, x * MINI_UNIT, 0X660033);
			else if (map[x][y] == '0')
				bloc_draw(img, y * MINI_UNIT, x * MINI_UNIT, 0X000099);
			y++;
		}
		x++;
	}
}

void	player_render(t_img *img, t_player player, t_map map)
{
	int	i;
	float x;
	float y;
	t_ray v_ray;
	t_ray h_ray;

	v_ray = vert_ray_init(&player, 0, map);
	h_ray = hor_ray_init(&player, 0, map);
	x = player.x;
	y = player.y;

	i = 0;
	while (i++ < 10)
	{
		x += player.dx;
		y += player.dy;
		my_pixel_put(img, (int)x, (int)y, 0XFFFFFF);
	}
	if (v_ray.len < h_ray.len)
		draw_ray(img, v_ray, 0XFFFF00);
	else
		draw_ray(img, h_ray, 0XFFFF00);
}

int	rendering(t_data *data)
{
	t_img	img;
	
	mlx_clear_window(data->mlx, data->win.ptr);
	img.ptr =  mlx_new_image(data->mlx, WIN_WIDTH, WIN_HIGHT);
	img.addr = mlx_get_data_addr(img.ptr, &img.bit_per_pixel, &img.line_length,
				&img.endian);
	map_render(&img, data->main_map.map);
	player_render(&img, data->player, data->main_map);
	mlx_put_image_to_window(data->mlx, data->win.ptr, img.ptr, 0, 0);
	mlx_destroy_image(data->mlx , img.ptr);
	return (0);
}
