/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c	                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:32:24 by yagnaou           #+#    #+#             */
/*   Updated: 2022/10/03 16:28:19 by yagnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	print_and_exit(char *str)
{
	printf("%s\n", str);
	exit(EXIT_FAILURE);
}

void	do_this(t_map *map, int i, int j, int *count, int len)
{
	if (map->map[i][j] == '\n')
		print_and_exit("New line found in the map!");
	if (!ft_isalnum(map->map[i][j]))
		print_and_exit("Found another character in the map!");
	check_for_player(map->map[i][j], count);
	check_top_bottom_tab(map, i, j, len);
	if (map->map[i][j] == '0')
	{
		check_for_end(map, i, j);
		check_for_space(map, i, j);
	}
}

void	map_checking(t_map *map)
{
	int	i;
	int	j;
	int	len;
	int	count;

	len = 0;
	i = 0;
	count = 0;
	while (map->map[len])
		len++;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			do_this(map, i, j, &count, len);
			j++;
		}
		i++;
	}
	if (count != 1)
		print_and_exit("One player needed in the map!");
}

void	read_map(int fd, t_data *data)
{
	int     i;
    char    *line;
    char    *c;

    i = 1;
    c = ft_calloc(sizeof(char) , 2);
    line = ft_calloc(sizeof(char) , 1);
	fd = open("map.cub", O_RDONLY);
    while (i > 0)
    {
        i = read(fd, c, 1);
        if (i <= 0)
            break;
        line = ft_strjoin(line, c);
    }
	check_for_newline(line);
	data->main_map.map = ft_split(line, '\n');
	map_checking(&data->main_map);
}

