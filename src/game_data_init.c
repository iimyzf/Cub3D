/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_data_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <azabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:55:27 by azabir            #+#    #+#             */
/*   Updated: 2022/10/07 12:06:14 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	get_colors(t_textures text, int x,int y)
{
	char    *pixel;
	int	i = 0;
	fprintf(stderr, "line_len = %d\n", text.img.line_length);
	pixel = text.img.addr + (y * text.img.line_length + x * (text.img.bit_per_pixel / 8));
	i = *(int *)pixel;
	return (i);
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
	// data->text.img.ptr = mlx_xpm_file_to_image(data->mlx, "tex.xpm", &data->text.img.x, &data->text.img.y);
	// fprintf(stderr, "x = %d y = %d\n", data->text.img.x, data->text.img.y);
	// data->text.img.addr = mlx_get_data_addr(data->text.img.ptr, &data->text.img.bit_per_pixel, &data->text.img.line_length, &data->text.img.endian);
	// fprintf(stderr, "color = %X\n", get_colors(data->text, 5, 5));
	return (0);
}
