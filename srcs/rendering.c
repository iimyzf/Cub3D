/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:56:49 by azabir            #+#    #+#             */
/*   Updated: 2022/10/28 23:02:33 by yagnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

t_ray	short_ray_cast(t_player player, t_map map, float ray_ang)
{
	t_ray	v_ray;
	t_ray	h_ray;

	h_ray = hor_ray_init(&player, ray_ang, map);
	v_ray = vert_ray_init(&player, ray_ang, map);
	if (h_ray.len > v_ray.len)
	{
		ray_add_wall_data(&v_ray, map);
		return (v_ray);
	}
	else
	{
		ray_add_wall_data(&h_ray, map);
		return (h_ray);
	}
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
		draw_wall(img, ray_index, rays[ray_index], rays[ray_index].text);
		ray_index ++;
		ray_ang += s;
	}
	return (rays);
}

void	player_render(t_img *img, t_player player, t_ray *rays)
{
	int		i;
	float	x;
	float	y;

	x = player.x;
	y = player.y;
	i = 0;
	while (i < WIN_WIDTH)
	{
		draw_ray(img, rays[i], 0x3333FF);
		i += 50;
	}
}

int	rendering(t_data *data)
{
	t_img	img;
	t_ray	*rays;

	if (data->ch)
	{
		mlx_clear_window(data->mlx, data->win.ptr);
		img = img_init(data);
		rays = rays_render(&img, data->player, data->main_map);
		free(rays);
		mlx_put_image_to_window(data->mlx, data->win.ptr, img.ptr, 0, 0);
		mlx_destroy_image(data->mlx, img.ptr);
	}
	data->ch = 0;
	return (0);
}
