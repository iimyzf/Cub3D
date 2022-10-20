/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <azabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 22:07:53 by azabir            #+#    #+#             */
/*   Updated: 2022/10/07 15:03:05 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	key_hook(int keycode, t_data *data)
{
	char	**map;
	
	map = data->main_map.map;
	if (keycode == 123)
		data->player.ang.value -= RO_SPEED;
	if (keycode == 124)
		data->player.ang.value += RO_SPEED;
	player_update(&data->player, &data->player.ang.value, data->main_map.map);
	//fprintf(stderr, "key = %d\n", keycode);
	// if (!data->player.can_move_f || !data->player.can_move_b)
	//  	add_collision_trans(&data->player, data->main_map.map);
	if ((keycode == 126 || keycode == 13) && data->player.can_move_f)
	{
		data->player.x += data->player.dx * SPEED;
		data->player.y += data->player.dy * SPEED;
	}
	if ((keycode == 125 || keycode == 1) && data->player.can_move_b)
	{
		data->player.x -= data->player.dx * SPEED;
		data->player.y -= data->player.dy * SPEED;
	}
	// if (keycode == 2)
	// {
	// 	data->player.x += 1;
	// }
	// if (keycode == 0)
	// 	data->player.x -= 1;
	if (keycode == 53)
		exit (1);
	rendering(data);
	return (0);
}
