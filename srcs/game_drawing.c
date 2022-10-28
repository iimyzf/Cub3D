/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_drawing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <azabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:26:52 by azabir            #+#    #+#             */
/*   Updated: 2022/10/28 19:27:23 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (is_in_win(x, y))
	{
		pixel = img->addr + (y * img->line_length + x
				* (img->bit_per_pixel / 8));
		*(int *)pixel = color;
	}
}

void	draw_ray(t_img *img, t_ray ray, int color)
{
	int		i;
	float	x;
	float	y;

	x = ray.start.x;
	y = ray.start.y;
	i = 0;
	while (i <= ray.step && i < 5000)
	{
		my_pixel_put(img, x * SCAL, y * SCAL, color);
		x += ray.dx ;
		y += ray.dy ;
		i += 1;
	}
}

void	draw_wall(t_img *img, int index, t_ray ray, t_texture text)
{
	int		start;
	int		color;

	start = 0;
	ray.wall_start = (WIN_HIGHT / 2) - (ray.wall_hight / 2);
	ray.wall_end = (WIN_HIGHT / 2) + (ray.wall_hight / 2);
	if (ray.wall_end > WIN_HIGHT)
		ray.wall_end = WIN_HIGHT;
	while (start < ray.wall_start)
	{
		my_pixel_put(img, index, start, img->c_clr);
		start++;
	}
	while (start <= ray.wall_end)
	{
		color = text.colors[ray.color_index][((start - ray.wall_start)
				* text.img.y) / ray.wall_hight];
		my_pixel_put(img, index, start, color);
		start++;
	}
	while (start <= WIN_HIGHT)
	{
		my_pixel_put(img, index, start, img->f_clr);
		start++;
	}
}
