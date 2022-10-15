/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_data_update.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <azabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:07:40 by azabir            #+#    #+#             */
/*   Updated: 2022/10/07 16:39:30 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	add_collision_trans(t_player *player, char **map)
{
	int	x;
	int	y;
	
	x = (player->x + player->dx * COL_SPEED) / UNIT;
	y = (player->y) / UNIT;
	if (map[y][x] != '1')
		player->x += player->dx * COL_SPEED;
	x = (player->x) / UNIT ;
	y = (player->y + player->dy * COL_SPEED) / UNIT;
	if (map[y][x] != '1')
		player->y += player->dy * COL_SPEED;
}

void	ang_update(t_ang *ang, float value)
{
	ang->value = value;
	ang->to_up = 0;
	ang->to_right = 0;
	ang->y_ofs = 0;
	ang->x_ofs = 1;
	if (ang->value > 360)
		ang->value -= 360;
	if (ang->value < 0)
		ang->value += 360;
	if (ang->value > 180 && ang->value < 360)
	{
		ang->to_up = 1;
		ang->y_ofs = 1;
	}
	if (ang->value < 90 || ang->value > 270)
	{
		ang->to_right = 1;
		ang->x_ofs = 0;
	}
}

int	check_sides(t_player *player, float *ang, char **map, int direct)
{
	int		x;
	int		y;
	int		i;

	i = 0;
	x = (player->x + (cos((*ang + 50) * RAD) * SPEED - player->ang.x_ofs) * direct) / UNIT;
	y = (player->y + (sin((*ang + 50) * RAD) * SPEED - player->ang.y_ofs) * direct) / UNIT;
	if (map[y][x] == '1')
		i++;
	x = (player->x + (cos((*ang - 50) * RAD) * SPEED - player->ang.x_ofs) * direct) / UNIT;
	y = (player->y + (sin((*ang - 50) * RAD) * SPEED - player->ang.y_ofs) * direct) / UNIT;
	if (map[y][x] == '1')
		i++;
	if (i == 2)
		return (1);
	return (0);
}

void	player_update(t_player *player, float *ang, char **map)
{
	int	x;
	int	y;

	ang_update (&player->ang, *ang);
	player->dx = cos(*ang * RAD);
	player->dy = sin(*ang * RAD);
	x = (player->x + player->dx * SPEED - player->ang.x_ofs) / UNIT;
	y = (player->y + player->dy * SPEED - player->ang.y_ofs) / UNIT;
	player->can_move_f = 1;
	player->can_move_b = 1;
	if (check_sides(player, ang, map, 1) || map[y][x] == '1')
		player->can_move_f = 0;
	x = (player->x - player->dx * SPEED - player->ang.x_ofs) / UNIT;
	y = (player->y - player->dy * SPEED - player->ang.y_ofs) / UNIT;
	if (check_sides(player, ang, map, -1) || map[y][x] == '1')
		player->can_move_b = 0;
	//fprintf(stderr, "player angel = %f\r", player->ang.value);
}
