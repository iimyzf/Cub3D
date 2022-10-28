/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <azabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:39:11 by azabir            #+#    #+#             */
/*   Updated: 2022/10/28 19:28:38 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	ray_init(t_player *player, t_ray *ray, float ang)
{
	ray->start.x = player->x;
	ray->start.y = player->y;
	ang_update(&ray->ang, player->ang.value + ang);
	ray->ang_tg = tan(ray->ang.value * (M_PI / 180));
	ray->ang_addj = cos((ray->ang.value - player->ang.value) * (M_PI / 180));
}

void	ray_add_wall_data(t_ray *ray, t_map map)
{
	ray->wall_hight = (UNIT * WIN_WIDTH) / (ray->len * ray->ang_addj);
	ray->dx = ray->end.x - ray->start.x;
	ray->dy = ray->end.y - ray->start.y;
	ray->step = fabs(ray->dx);
	if (fabs(ray->dy) >= fabs(ray->dx))
		ray->step = fabs(ray->dy);
	ray->dx = ray->dx / ray->step;
	ray->dy = ray->dy / ray->step;
	if (ray->is_vert)
		ray->color_index = ((int)(ray->end.y) % UNIT)
			* (map.text.no.img.x / UNIT);
	else
		ray->color_index = ((int)(ray->end.x) % UNIT)
			* (map.text.no.img.x / UNIT);
}

void	ray_casting(t_ray *ray, t_map map)
{
	float	x_ofs;
	float	y_ofs;

	x_ofs = ray->ang.x_ofs;
	y_ofs = ray->ang.y_ofs;
	while (is_in_map(map, ray->end.x, ray->end.y)
		&& !is_a_wall(map, ray->end.x - x_ofs, ray->end.y - y_ofs))
	{
		ray->end.x += ray->x_step;
		ray->end.y += ray->y_step;
	}
	ray->len = sqrt((ray->start.x - ray->end.x) * (ray->start.x - ray->end.x)
			+ (ray->start.y - ray->end.y) * (ray->start.y - ray->end.y));
}

t_ray	vert_ray_init(t_player *player, float ang, t_map map)
{
	t_ray	v_ray;

	ray_init(player, &v_ray, ang);
	v_ray.is_vert = 1;
	v_ray.wall_color = 0x3333FF;
	v_ray.end.x = ((int)v_ray.start.x / UNIT) * UNIT;
	if (v_ray.ang.to_right)
		v_ray.end.x += UNIT;
	v_ray.end.y = v_ray.start.y - v_ray.ang_tg * (v_ray.start.x - v_ray.end.x);
	if (!v_ray.ang.to_up && v_ray.end.y < 0)
		v_ray.end.y *= -1;
	v_ray.x_step = UNIT;
	if (!v_ray.ang.to_right)
		v_ray.x_step *= -1;
	v_ray.y_step = v_ray.ang_tg * v_ray.x_step;
	v_ray.ang.y_ofs = 0;
	ray_casting(&v_ray, map);
	if (v_ray.ang.to_right)
		v_ray.text = map.text.ea;
	else
		v_ray.text = map.text.we;
	return (v_ray);
}

t_ray	hor_ray_init(t_player *player, float ang, t_map map)
{
	t_ray	h_ray;

	ray_init(player, &h_ray, ang);
	h_ray.is_vert = 0;
	h_ray.wall_color = 0xFFFF00;
	h_ray.end.y = ((int)h_ray.start.y / UNIT) * UNIT;
	if (!h_ray.ang.to_up)
		h_ray.end.y += UNIT;
	h_ray.end.x = h_ray.start.x + (h_ray.end.y - h_ray.start.y) / h_ray.ang_tg;
	h_ray.y_step = UNIT;
	if (h_ray.ang.to_up)
		h_ray.y_step *= -1;
	h_ray.x_step = UNIT / h_ray.ang_tg;
	if (!h_ray.ang.to_right && h_ray.x_step > 0)
		h_ray.x_step *= -1;
	if (h_ray.ang.to_right && h_ray.x_step < 0)
		h_ray.x_step *= -1;
	h_ray.ang.x_ofs = 0;
	if (h_ray.ang.to_up)
		h_ray.text = map.text.no;
	else
		h_ray.text = map.text.so;
	ray_casting(&h_ray, map);
	return (h_ray);
}
