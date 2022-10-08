/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_drawing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <azabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:26:52 by azabir            #+#    #+#             */
/*   Updated: 2022/10/07 18:11:15 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	if (is_in_win(x, y))
	{
		char    *pixel;
		pixel = img->addr + (y * img->line_length + x * (img->bit_per_pixel / 8));
		*(int *)pixel = color;
	}
}

void	bloc_draw(t_img *img, int x, int y, int color)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < (MINI_UNIT - 1))
	{
		j = 0;
		while (j < (MINI_UNIT - 1))
		{
			my_pixel_put(img, x + j, y + i, color);
			j++;
		}
		i++;
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
		my_pixel_put(img, x, y, color);
		x += ray.dx ;
		y += ray.dy ;
		i += 1;
	}
}

void	dda_algo(t_img *img, float x0, float y0, float x1, float y1, int color)
{
	float	dx;
	float	dy;
	float	steps;
	float ix;
	float iy;
	float x;
	float y;

	x = x0;
	y = y0;
	dx = x1 - x0;
	dy = y1 - y0;
	steps = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy);
	ix = dx / steps;
	iy = dy / steps;
	for (int i = 0; i <= steps && i < 5000; i++)
	{
		
		my_pixel_put(img, x, y, color);
		x += ix;
		y += iy;
	}
}