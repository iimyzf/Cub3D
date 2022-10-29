/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 22:23:39 by yagnaou           #+#    #+#             */
/*   Updated: 2022/10/27 20:44:41 by yagnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	print_and_exit(char *str)
{
	printf("%s\n", str);
	exit(EXIT_FAILURE);
}

int	ft_isplayer(int c)
{
	if (c == 'W' || c == 'N' || c == 'E' || c == 'S')
		return (1);
	return (0);
}

void	do_this(char **map, int i, int j, int *count)
{
	int	len;

	len = 0;
	while (map[len])
		len++;
	if (!ft_isalnum(map[i][j]))
		print_and_exit("Found another character in the map!");
	check_for_player(map[i][j], count);
	check_udrl(map, i, j, len);
	if ((map[i][j] == '0' || ft_isplayer(map[i][j])))
	{
		check_for_end(map, i, j);
		check_for_space(map, i, j);
	}
}

void	player_function(char **map, int i, int j, t_data *data)
{
	if (ft_isplayer(map[i][j]))
	{
		data->player.x = (j + 0.5) * UNIT;
		data->player.y = (i + 0.5) * UNIT;
		data->player.type = map[i][j];
		map[i][j] = '0';
	}
}

void	map_checking(char **map, t_data *data)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '\n')
				do_this(map, i, j, &count);
			player_function(map, i, j, data);
			j++;
		}
		i++;
	}
	if (count != 1)
		print_and_exit("One player needed in the map!");
}
