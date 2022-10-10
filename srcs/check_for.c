/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 12:03:03 by yagnaou           #+#    #+#             */
/*   Updated: 2022/10/07 12:48:14 by yagnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub.h"

void	check_for_end(t_map *map, int i, int j)
{
	if (map->map[i][j - 1] == '\0' || map->map[i][j + 1] == '\0'
		|| map->map[i - 1][j] == '\0' || map->map[i + 1][j] == '\0'
		|| i == 0 || j == 0)
		print_and_exit("Map isn't surrounded by 1's!");
}

void	check_for_space(t_map *map, int i, int j)
{
	if (map->map[i][j - 1] == ' ' || map->map[i][j + 1] == ' '
		|| map->map[i - 1][j] == ' ' || map->map[i + 1][j] == ' '
		|| i == 0 || j == 0)
		print_and_exit("Map isn't surrounded by 1's!");
}

void	check_top_bottom_tab(t_map *map, int i, int j, int len)
{
	if (map->map[i][j] == '\t')
		print_and_exit("Found tab in the map");
	if (map->map[i][j] == '0' && ((i == 0 || j == 0) || (i == len - 1)))
		print_and_exit("Map isn't surrounded by 1's!");
}

void	check_for_newline(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[len])
		len++;
	while (str[i])
	{
		if (str[i] == '\n' || str[0] == '\n' || str[len - 1] == '\n')
		{
			if (str[i + 1] != '1' && str[i + 1] != '\0')
				print_and_exit("Found new line!!!!!!!");
		}
		i++;
	}
}

int	check_for_player(char c, int *count)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		*count += 1;
	return (*count);
}
