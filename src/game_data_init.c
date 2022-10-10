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
	return (0);
}
