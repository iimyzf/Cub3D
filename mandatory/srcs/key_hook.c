/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 22:07:53 by azabir            #+#    #+#             */
/*   Updated: 2022/10/29 17:59:48 by yagnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	ft_exit(t_data *data)
{
	(void) data;
	exit(1);
	return (1);
}

void	f_move(t_data *data)
{
	if (!data->player.can_move_f)
		add_collision_trans(&data->player, data->main_map.map, 1);
	else
	{
		data->player.x_slid = 0;
		data->player.y_slid = 0;
		data->player.x += data->player.dx * SPEED;
		data->player.y += data->player.dy * SPEED;
	}
}

void	b_move(t_data *data)
{
	if (!data->player.can_move_b)
		add_collision_trans(&data->player, data->main_map.map, -1);
	else
	{
		data->player.x_slid = 0;
		data->player.y_slid = 0;
		data->player.x -= data->player.dx * SPEED;
		data->player.y -= data->player.dy * SPEED;
	}
}

int	key_hook(int keycode, t_data *data)
{
	char	**map;

	map = data->main_map.map;
	if (keycode == 123)
		data->player.ang.value -= RO_SPEED;
	if (keycode == 124)
		data->player.ang.value += RO_SPEED;
	player_update(&data->player, &data->player.ang.value, data->main_map.map);
	if ((keycode == 126 || keycode == 13))
		f_move(data);
	if ((keycode == 125 || keycode == 1))
		b_move(data);
	if (keycode == 2)
		can_move_side(&data->player, data->main_map, 0);
	if (keycode == 0)
		can_move_side(&data->player, data->main_map, 1);
	if (keycode == 53)
		ft_exit (data);
	data->ch = 1;
	return (0);
}

// int	mouse_hook(int x, int y, t_data *data)
// {
// 	(void) x;
// 	(void) y;
// 	if (hook(data) == 2)
// 		data->player.ang.value -= RO_SPEED / 2;
// 	if (hook(data) == 1)
// 		data->player.ang.value += RO_SPEED / 2;
// 	player_update(&data->player, &data->player.ang.value, data->main_map.map);
// 	mlx_mouse_move(data->win.ptr, WIN_WIDTH / 2, 100);
// 	mlx_mouse_hide();
// 	data->ch = 1;
// 	return (0);
// }
