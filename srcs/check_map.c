/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 22:23:39 by yagnaou           #+#    #+#             */
/*   Updated: 2022/10/23 21:14:14 by yagnaou          ###   ########.fr       */
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

void	do_this(char **map, int i, int j, int *count, int len)
{
	if (!ft_isalnum(map[i][j]))
		print_and_exit("---> Found another character in the map!");
	check_for_player(map[i][j], count);
	check_udrl(map, i, j, len);
	if (map[i][j] == '0')
	{
		check_for_end(map, i, j);
		check_for_space(map, i, j);
	}
}

char *get_next_line(int fd)
{
    int		i;
    int		ret;
    char	c;
    char	line[8000000];

	i = 0;
	ret = 1;
	ft_bzero(line, 8000000);
    while((ret = read(fd, &c, 1) > 0))
    {
        line[i++] = c;
        if (c == '\n')
            break ;
    }
    if (line[0] == 0)
        return NULL;
    return (ft_strdup(line));
}

void	map_checking(char **map, t_data *data)
{
	int	i;
	int	j;
	int	len;
	int	count;

	len = 0;
	i = 0;
	count = 0;
	while (map[len])
		len++;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			//fprintf(stderr, "This is c: [%c]\n", map[i][j]);
			if (map[i][j] != '\n')
				do_this(map, i, j, &count, len);
			if (ft_isplayer(map[i][j]))
			{
				data->player.x = (j + 0.5) * UNIT;
				data->player.y = (i + 0.5) * UNIT;
				data->player.type = map[i][j];
				map[i][j] = '0';
				//fprintf(stderr, "player x = %d, player y = %d \n", i, j);
			}
			j++;
		}
		i++;
	}
	if (count != 1)
		print_and_exit("One player needed in the map!");
}

char	**read_map(char *str)
{
	char	**line;
	int		fd;
	int		i;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		exit(-1);
	line = (char **)malloc(sizeof(char *) * 10000);
	i = 0;
	line[i] = get_next_line(fd);
	if (!line[i])
		exit(-1);
	while (line[i++])
		line[i] = get_next_line(fd);
	close(fd);
	return (line);
}

char	**get_first_six_lines(char **file)
{
	int		i;
	int		j;
	char	**lines;

	i = 0;
	j = 0;
	lines = (char **)malloc(sizeof(char *) * 7);
	while (file[i] && j < 6)
	{
		if (file[i] && file[i][0] != '\n')
		{
			lines[j] = ft_strdup(file[i]);
			j++;
		}
		i++;
	}
	fprintf(stderr, "i = %d\n", i); //
	lines[j] = NULL;
	return (lines);
}

char	**get_the_map(char **file)
{
	int		i;
	int		j;
	int		len;
	char	**map;

	i = 0;
	j = 0;
	len = 0;
	while (file[len])
		len++;
	map = (char **)malloc(sizeof(char *) * len);
	while (file[i] && j < 6)
	{
		if (file[i] && file[i][0] != '\n')
			j++;
		i++;
	}
	j = 0;
	while (file[i] && file[i][0] == '\n')
		i++;
	while (file[i] && file[i][0] != '\n')
		map[j++] = ft_strdup(file[i++]);
	map[j] = NULL;
	return (map);
}
