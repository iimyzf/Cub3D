/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:29:15 by yagnaou           #+#    #+#             */
/*   Updated: 2022/10/27 20:44:17 by yagnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	get_image(char *path, t_data *data, t_texture *text)
{
	text->img.ptr = mlx_xpm_file_to_image(data->mlx, path,
			&text->img.x, &text->img.y);
	if (!text->img.ptr)
		return (0);
	text->img.addr = mlx_get_data_addr(text->img.ptr,
			&text->img.bit_per_pixel,
			&text->img.line_length, &text->img.endian);
	fill_colors2(text);
	return (1);
}

void	check_for_textures(char *string, char *str, t_data *data)
{
	if (!ft_strcmp(string, "NO"))
		if (!get_image(str, data, &data->main_map.text.no))
			print_and_exit("Invalid NO path!");
	if (!ft_strcmp(string, "SO"))
		if (!get_image(str, data, &data->main_map.text.so))
			print_and_exit("Invalid SO path!");
	if (!ft_strcmp(string, "WE"))
		if (!get_image(str, data, &data->main_map.text.we))
			print_and_exit("Invalid WE path!");
	if (!ft_strcmp(string, "EA"))
		if (!get_image(str, data, &data->main_map.text.ea))
			print_and_exit("Invalid EA path!");
}

void	which_str2(char *str, char *string, t_data *data)
{
	if (!ft_strcmp(string, "F") || !ft_strcmp(string, "C"))
	{
		if (!ft_strcmp(string, "C"))
			data->main_map.text.the_color.c = get_color(str, data);
		else
			data->main_map.text.the_color.f = get_color(str, data);
	}
	else
		print_and_exit("Error occured! Please check again!");
}

void	which_str(char *str, t_data *data)
{
	char	*string;

	string = get_str(str);
	if (ft_strlen(str) > ft_strlen(string) + 1)
		str += ft_strlen(string);
	while (*str && (*str == ' ' || *str == '\t'))
		str++;
	if (!ft_strcmp(string, "NO") || !ft_strcmp(string, "SO")
		|| !ft_strcmp(string, "WE") || !ft_strcmp(string, "EA"))
		check_for_textures(string, str, data);
	else
		which_str2(str, string, data);
	free(string);
}

void	get_element(char **map, t_data *data)
{
	int		i;
	int		j;
	int		count;
	char	*str;

	i = 0;
	j = 0;
	count = 0;
	while (map[i] && j < 6)
	{
		if (map[i] && map[i][0] != '\n')
		{
			str = trimming(map[i]);
			if (*str)
			{
				check_for_fc(*str, &count);
				which_str(str, data);
				j++;
			}
			free(str);
		}
		i++;
	}
	if (count != 1)
		print_and_exit("Error occured! Please check again!");
}
