/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 12:03:03 by yagnaou           #+#    #+#             */
/*   Updated: 2022/10/19 11:53:12 by yagnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	check_for_end(char **map, int i, int j)
{
	if (map[i][j - 1] == '\0' || map[i][j + 1] == '\0' || map[i - 1][j] == '\0' || map[i + 1][j] == '\0' || i == 0 || j == 0)
		print_and_exit("--- Map isn't surrounded by 1's!");
}

void	check_for_space(char **map, int i, int j)
{
	if (map[i][j - 1] == ' ' || map[i][j + 1] == ' ' || map[i - 1][j] == ' ' || map[i + 1][j] == ' ' || i == 0 || j == 0)
		print_and_exit("+++ Map isn't surrounded by 1's!");
}

void	check_udrl(char **map, int i, int j, int len)
{
	if (map[i][j] == '\t')
		print_and_exit("Found tab in the map");
	if (map[i][j] == '0' && (i == 0 || j == 0))
		print_and_exit("*** Map isn't surrounded by 1's!");
	if (map[i][j] == '0' && (i == len - 1 || map[i][j + 1] == '\n'))
		print_and_exit("xxx Map isn't surrounded by 1's!");
}

int	check_for_player(char c, int *count)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		*count += 1;
	return (*count);
}
