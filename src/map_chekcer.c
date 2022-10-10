/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_chekcer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <azabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:26:34 by azabir            #+#    #+#             */
/*   Updated: 2022/10/06 14:42:36 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

// int	ft_strlen(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str && str[i] != '\0')
// 		i++;
// 	return (i);
// }

// char	*ft_strjoin(char *str, char *buf)
// {
// 	char	*ptr;
// 	size_t	j;

// 	if (!str || !buf)
// 		return (NULL);
// 	j = ft_strlen(str);
// 	j +=1;
// 	ptr = malloc (sizeof(char) * (j + 1));
// 	if (!ptr)
// 		return (NULL);
// 	j = 0;
// 	while (str[j])
// 	{
// 		ptr[j] = str[j];
// 		j++;
// 	}
// 	while (*buf)
// 		ptr[j++] = *buf++;
// 	ptr [j] = 0;
// 	free (str);
// 	return (ptr);
// }

void	map_check(t_data *data)
{
	int		i;
	char	*line;
	char	*c;

	i = 1;
	c = calloc(sizeof(char) , 2);
	line = calloc(sizeof(char) , 1);
	while (i > 0)
	{
		i = read(data->fd, c, 1);
		if (i <= 0)
			break;
		line = ft_strjoin(line, c);
	}
	data->main_map.map = ft_split(line, '\n');
	i = 0;
	data->main_map.x_len = 0;
	while (data->main_map.map && data->main_map.map[i])
	{
		if(data->main_map.x_len < ft_strlen(data->main_map.map[i]))
			data->main_map.x_len = ft_strlen(data->main_map.map[i]);
		i++;
	}
	data->main_map.y_len = i;
}