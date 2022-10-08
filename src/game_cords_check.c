/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_cords_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <azabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:34:01 by azabir            #+#    #+#             */
/*   Updated: 2022/10/07 11:10:47 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int	is_in_win(float x, float y)
{
	if (x < 0 || x > WIN_WIDTH || y < 0 || y > WIN_HIGHT - 1)
		return (0);
	return (1);
}

int	is_in_map(t_map map,float x, float y)
{
	
	if (x < 0 || x > map.x_len * MINI_UNIT || y < 0 || y > map.y_len * MINI_UNIT)
		return (0);
	return (1);
}

int	is_a_wall(t_map main_map, float x, float y)
{
	char	**map;

	map = main_map.map;
	if (is_in_map(main_map, x, y) && map[(int)y / MINI_UNIT][(int)x / MINI_UNIT] == '1')
	{
		return (1);
	}
	return (0);
}
