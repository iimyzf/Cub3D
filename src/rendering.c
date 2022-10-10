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

#include "../includes/cub.h"


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

t_ray	short_ray_cast(t_player player, t_map map, float ray_ang)
{
	t_ray	v_ray;
	t_ray	h_ray;

	h_ray = hor_ray_init(&player, ray_ang, map);
	v_ray = vert_ray_init(&player, ray_ang, map);
	if (h_ray.len > v_ray.len)
		return (v_ray);
	else
		return (h_ray);
}

t_ray	*rays_render(t_img *img, t_player player, t_map map)
{
	float	ray_ang;
	int		ray_index;
	float	s;
	t_ray	*rays;

	rays = malloc(sizeof(t_ray) * WIN_WIDTH);
	s = 60.0000 / WIN_WIDTH;
	ray_index = 0;
	ray_ang = -30;
	while (ray_index < WIN_WIDTH)
	{
		rays[ray_index] = short_ray_cast(player, map, ray_ang);
		draw_wall(img, ray_index, rays[ray_index].wall_hight, 0x3333FF);
		ray_index ++;
		ray_ang += s;
	}
	return (rays);
	//fprintf(stderr, "s = %f\r", s);
}

void	player_render(t_img *img, t_player player, t_map map, t_ray *rays)
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
		my_pixel_put(img, (int)(x * SCAL), (int)(y * SCAL), 0XFFFFFF);
	}
	i = 0;
	while (i < WIN_WIDTH)
	{
		draw_ray(img, rays[i], 0x99FF99);
		i += 50;
	}
}

int	rendering(t_data *data)
{
	t_img	img;
	t_ray	*rays;
	
	mlx_clear_window(data->mlx, data->win.ptr);
	img.ptr =  mlx_new_image(data->mlx, WIN_WIDTH, WIN_HIGHT);
	img.addr = mlx_get_data_addr(img.ptr, &img.bit_per_pixel, &img.line_length,
				&img.endian);
	rays = rays_render(&img, data->player, data->main_map);
	map_render(&img, data->main_map.map);
	player_render(&img, data->player, data->main_map, rays);
	free(rays);
	mlx_put_image_to_window(data->mlx, data->win.ptr, img.ptr, 0, 0);
	mlx_destroy_image(data->mlx , img.ptr);
	return (0);
}
