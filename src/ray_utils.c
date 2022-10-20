/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <azabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:39:11 by azabir            #+#    #+#             */
/*   Updated: 2022/10/07 18:19:43 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	ray_init(t_player *player, t_ray *ray, float ang)
{
	ray->start.x = player->x;
	ray->start.y = player->y;
	ang_update(&ray->ang, player->ang.value + ang);
	ray->ang_tg = tan(ray->ang.value * RAD);
	ray->ang_addj = cos((ray->ang.value - player->ang.value) * RAD);
}

void	ray_casting(t_ray *ray, t_map map)
{
	float x_ofs;
	float y_ofs;

	x_ofs = ray->ang.x_ofs;
	y_ofs = ray->ang.y_ofs;
	while (is_in_map(map, ray->end.x, ray->end.y) &&
			!is_a_wall(map, ray->end.x - x_ofs, ray->end.y - y_ofs))
	{
		ray->end.x += ray->x_step;
		ray->end.y += ray->y_step;
		//write(2, "here\n", 5);
	}
	ray->len = sqrt((ray->start.x - ray->end.x) * (ray->start.x - ray->end.x) +
					(ray->start.y - ray->end.y) * (ray->start.y - ray->end.y));
	ray->wall_hight = (UNIT * WIN_WIDTH) / (ray->len * ray->ang_addj);
}

t_ray	vert_ray_init(t_player *player, float ang, t_map map)
{
	t_ray v_ray;
	
	ray_init(player, &v_ray, ang);
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
	v_ray.dx = v_ray.end.x - v_ray.start.x;
	v_ray.dy = v_ray.end.y - v_ray.start.y;
	v_ray.step = fabs(v_ray.dx);
	if (fabs(v_ray.dy) >= fabs(v_ray.dx))
		v_ray.step = fabs(v_ray.dy);
	v_ray.dx = v_ray.dx / v_ray.step;
	v_ray.dy = v_ray.dy / v_ray.step;
	v_ray.color_index = ((int)(v_ray.end.y) % UNIT) * (map.text.img.x / UNIT);
	return (v_ray);
}

t_ray	hor_ray_init(t_player *player, float ang, t_map map)
{
	t_ray h_ray;

	ray_init(player, &h_ray, ang);
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
	ray_casting(&h_ray, map);
	h_ray.dx = h_ray.end.x - h_ray.start.x;
	h_ray.dy = h_ray.end.y - h_ray.start.y;
	h_ray.step = fabs(h_ray.dx);
	if (fabs(h_ray.dy) >= fabs(h_ray.dx))
		h_ray.step = fabs(h_ray.dy);
	h_ray.dx = h_ray.dx / h_ray.step;
	h_ray.dy = h_ray.dy / h_ray.step;
	h_ray.color_index = ((int)(h_ray.end.x) % UNIT) * (map.text.img.x / UNIT);
	return (h_ray);
}

