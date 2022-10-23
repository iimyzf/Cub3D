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

t_img	*img_init(t_data *data)
{
	t_img	*img;
	
	img->ptr = mlx_new_image(data->mlx, WIN_WIDTH , WIN_HIGHT);
	img->addr = mlx_get_data_addr(img->ptr, &img->bit_per_pixel, &img->line_length,
				&img->endian);
	img->c_clr = data->main_map.text.the_color.c;
	img->f_clr = data->main_map.text.the_color.f;
	return (img);
}

int	scean_init(t_data	*data)
{
	data->player.x = 200;
	data->player.y = 300;
	ang_update(&data->player.ang, INIT_ANG);
	player_update(&data->player, &data->player.ang.value, data->main_map.map);
	data->main_map.text.colors = data->main_map.text.no.colors;
	return (1);
}
