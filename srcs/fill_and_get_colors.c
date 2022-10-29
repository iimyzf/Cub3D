/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_and_get_colors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 22:55:45 by yagnaou           #+#    #+#             */
/*   Updated: 2022/10/25 22:57:26 by yagnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	get_colors2(t_texture text, int x, int y)
{
	char	*pixel;
	int		i;

	i = 0;
	if (x >= text.img.x || y >= text.img.y || x < 0 || y < 0)
		return (0);
	pixel = text.img.addr
		+ (y * text.img.line_length + x * (text.img.bit_per_pixel / 8));
	i = *(int *)pixel;
	return (i);
}

void	fill_colors2(t_texture *text)
{
	int	x;
	int	y;

	text->colors = malloc(sizeof(int *) * (text->img.x + 1));
	x = 0;
	while (x < text->img.x)
	{
		y = 0;
		text->colors[x] = malloc(sizeof(int ) * (text->img.y + 1));
		while (y < text->img.y)
		{
			text->colors[x][y] = get_colors2(*text, x, y);
			y++;
		}
		text->colors[x][y] = 0;
		x++;
	}
	text->colors[x] = NULL;
}
