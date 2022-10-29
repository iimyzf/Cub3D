/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:18:34 by yagnaou           #+#    #+#             */
/*   Updated: 2022/10/28 01:43:28 by yagnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

char	*get_next_line(int fd)
{
	int		i;
	char	c;
	char	line[8000000];

	i = 0;
	ft_bzero(line, 8000000);
	while (read(fd, &c, 1) > 0)
	{
		line[i++] = c;
		if (c == '\n')
			break ;
	}
	if (line[0] == 0)
		return (NULL);
	return (ft_strdup(line));
}

char	**read_map(char *str)
{
	char	**line;
	int		fd;
	int		i;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		exit(-1);
	line = (char **) malloc(sizeof(char *) * 100000);
	i = 0;
	line[i] = get_next_line(fd);
	if (!line[i])
		exit(-1);
	while (line[i++])
		line[i] = get_next_line(fd);
	close(fd);
	return (line);
}

char	**get_the_map(char **file)
{
	t_norm	norm;

	norm.i = 0;
	norm.j = 0;
	while (file[norm.i])
		norm.i++;
	norm.map = (char **) malloc(sizeof(char *) * norm.i + 1);
	norm.i = 0;
	while (file[norm.i] && norm.j < 6)
	{
		norm.tmp = trimming(file[norm.i]);
		if (norm.tmp && norm.tmp[0] != '\n'
			&& norm.tmp[0] != ' ' && norm.tmp[0] != '\t' && norm.tmp[0])
			norm.j++;
		norm.i++;
		free(norm.tmp);
	}
	norm.j = 0;
	while (file[norm.i] && (file[norm.i][0] == '\n' || file[norm.i][0] == '\t'))
		norm.i++;
	while (file[norm.i])
		norm.map[norm.j++] = ft_strdup(file[norm.i++]);
	norm.map[norm.j] = NULL;
	free_array(file);
	return (norm.map);
}
