/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_drawing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <azabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:26:52 by azabir            #+#    #+#             */
/*   Updated: 2022/10/07 16:13:08 by azabir           ###   ########.fr       */
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
	while (i <= ray.steps)
	{
		my_pixel_put(img, x, y, color);
		x += ray.dx;
		y += ray.dy;
	}
}