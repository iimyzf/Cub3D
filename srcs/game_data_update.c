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

void	add_collision_trans(t_player *player, char **map, int fact)
{
	int	x;
	int	y;
	int	i;
	
	i = 0;
	x = (player->x + player->dx * COL_SPEED * 4 * fact) / UNIT;
	y = (player->y) / UNIT;
	if (map[y][x] != '1')
	{
		player->x += player->dx * COL_SPEED * fact;
		i = 1;
	}
	x = (player->x) / UNIT ;
	y = (player->y + player->dy * COL_SPEED * 4 * fact) / UNIT;
	if (map[y][x] != '1' && !i)
			player->y += player->dy * COL_SPEED * fact;
}

int	can_move_side(t_player *player, t_map map,int	to_right)
{
	float	x;
	float	y;
	float	dx;
	float	dy;
	float ang;

	ang = player->ang.value + 90;
	if (to_right)
		ang = player->ang.value - 90;
	x = player->x + cos(ang * RAD) * SPEED * 2;
	y = player->y + sin(ang * RAD) * SPEED * 2;
	if (!(!player->can_move_b && !player->can_move_f) && map.map[(int)y / UNIT][(int)x / UNIT] != '1')
	{
		player->x = x - cos(ang * RAD) * SPEED;
		player->y = y - sin(ang * RAD) * SPEED;
		return (1);
	}
	return (0);
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
	x = (player->x + (cos((*ang + 30) * RAD) * 20 - player->ang.x_ofs) * direct) / UNIT;
	y = (player->y + (sin((*ang + 30) * RAD) * 20 - player->ang.y_ofs) * direct) / UNIT;
	if (map[y][x] == '1')
		i++;
	x = (player->x + (cos((*ang - 30) * RAD) * 20 - player->ang.x_ofs) * direct) / UNIT;
	y = (player->y + (sin((*ang - 30) * RAD) * 20 - player->ang.y_ofs) * direct) / UNIT;
	if (map[y][x] == '1')
		i++;
	if (i >= 1)
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
	x = (player->x + player->dx * 20 - player->ang.x_ofs) / UNIT;
	y = (player->y + player->dy * 20 - player->ang.y_ofs) / UNIT;
	player->can_move_f = 1;
	player->can_move_b = 1;
	if (check_sides(player, ang, map, 1) || map[y][x] == '1')
	 	player->can_move_f = 0;
	x = (player->x - player->dx * 20 - player->ang.x_ofs) / UNIT;
	y = (player->y - player->dy * 20 - player->ang.y_ofs) / UNIT;
	if (check_sides(player, ang, map, -1) || map[y][x] == '1')
		player->can_move_b = 0;
	//fprintf(stderr, "player angel = %f\r", player->ang.value);
}
