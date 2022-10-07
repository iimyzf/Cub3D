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

int	is_in_map(t_map map,int x, int y)
{
	x = x / UNIT;
	y = y / UNIT;
	
	if (x < 0 || x > map.x_len || y < 0 || y > map.y_len)
		return (0);
	return (1);
}
