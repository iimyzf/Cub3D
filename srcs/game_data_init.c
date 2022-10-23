/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_data_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:55:27 by azabir            #+#    #+#             */
/*   Updated: 2022/10/23 00:13:32 by yagnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	get_colors(t_textures text, int x,int y)
{
	char    *pixel;
	int	i = 0;
	//fprintf(stderr, "line_len = %d\n", text.img.line_length);
	if (x >= text.img.x || y >= text.img.y || x < 0 || y < 0)
		return (0);
	pixel = text.img.addr + (y * text.img.line_length + x * (text.img.bit_per_pixel / 8));
	i = *(int *)pixel;
	return (i);
}

void fill_colors(t_textures *text)
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
			text->colors[x][y] = get_colors(*text, x, y);
			y++;
		}
		text->colors[x][y] = 0;
		x++;
	}
	text->colors[x] = NULL;
}

t_img	*img_init(t_data *data)
{
	t_img	*img;
	
	img->x = data->main_map.x_len;
	img->y = data->main_map.y_len;
	img->ptr = mlx_new_image(data->mlx, img->x * UNIT , img->y * UNIT );
	img->addr = mlx_get_data_addr(img->ptr, &img->bit_per_pixel, &img->line_length,
				&img->endian);
	return (img);
}

int	scean_init(t_data	*data)
{
	data->player.x = 200;
	data->player.y = 300;
	ang_update(&data->player.ang, INIT_ANG);
	player_update(&data->player, &data->player.ang.value, data->main_map.map);
	// data->main_map.text.img.ptr = mlx_xpm_file_to_image(data->mlx, "texbb.xpm", &data->main_map.text.img.x, &data->main_map.text.img.y);
	// if (!data->main_map.text.img.ptr)
	// 	return (0);
	// data->main_map.text.img.addr = mlx_get_data_addr(data->main_map.text.img.ptr, &data->main_map.text.img.bit_per_pixel, &data->main_map.text.img.line_length, &data->main_map.text.img.endian);
	// fill_colors(&data->main_map.text);
	data->main_map.text.colors = data->main_map.text.no.colors;
	return (1);
}
