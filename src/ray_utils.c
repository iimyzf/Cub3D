/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <azabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:39:11 by azabir            #+#    #+#             */
/*   Updated: 2022/10/07 17:18:24 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	ray_init(t_player *player, t_ray *ray, float ang)
{
	ray->start.x = player->x;
	ray->start.y = player->y;
	ang_update(&ray->ang, player->ang.value + ang);
}

t_ray	vert_ray_init(t_player *player, float ang)
{
	t_ray v_ray;
	
	ray_init(player, &v_ray, ang);
	v_ray.end.x = ((int)v_ray.start.x / MINI_UNIT) * MINI_UNIT;
	if (v_ray.ang.to_right)
		v_ray.end.x += MINI_UNIT;
	v_ray.end.y = v_ray.start.y - tan(v_ray.ang.value * RAD) * (v_ray.start.x - v_ray.end.x);
	if (!v_ray.ang.to_up && v_ray.end.y < 0)
		v_ray.end.y *= -1;
	v_ray.x_step = MINI_UNIT;
	if (!v_ray.ang.to_right)
		v_ray.x_step *= -1;
	v_ray.y_step = tan(v_ray.ang.value * RAD) * v_ray.x_step;
	v_ray.dx = v_ray.end.x - v_ray.start.x;
	v_ray.dy = v_ray.end.y - v_ray.start.y;
	v_ray.step = v_ray.dx;
	if (fabs(v_ray.dy) > fabs(v_ray.dx))
		v_ray.step = v_ray.dy;
	v_ray.dx = v_ray.dx / v_ray.step; 
	v_ray.dy = v_ray.dy / v_ray.step; 
	return (v_ray);
}
