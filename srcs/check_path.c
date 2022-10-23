/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:29:15 by yagnaou           #+#    #+#             */
/*   Updated: 2022/10/23 18:27:32 by yagnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	get_colors2(t_texture text, int x,int y)
{
	char    *pixel;
	int	i = 0;
	//fprintf(stderr, "line_len = %d\n", text.img.line_length);
	if (x >= text.img.x || y >= text.img.y || x < 0 || y < 0)
		return (0);
	pixel = text.img.addr + (y * text.img.line_length + x * (text.img.bit_per_pixel / 8));
	i = *(int *)pixel;
	return (i);
}

void fill_colors2(t_texture *text)
{
	int	x;
	int	y;

	text->colors = malloc(sizeof(int *) * (text->img.x + 1));
	x = 0;
	while (x < text->img.x)
	{
		y = 0;
		text->colors[x] = malloc(sizeof(int ) * (text->img.y + 1));
		while (y < text->img.y)
		{
			text->colors[x][y] = get_colors2(*text, x, y);
			y++;
		}
		text->colors[x][y] = 0;
		x++;
	}
	text->colors[x] = NULL;
}

int	get_image(char *path, t_data *data, t_texture *text)
{
	//fprintf(stderr, "path = [%s]\n", path);
	text->img.ptr = mlx_xpm_file_to_image(data->mlx, path, &text->img.x, &text->img.y);
	if (!text->img.ptr)
		return (0);
	text->img.addr = mlx_get_data_addr(text->img.ptr, &text->img.bit_per_pixel, &text->img.line_length, &text->img.endian);
	fill_colors2(text);
	return (1);
}

unsigned int rgb_to_int(int r, int g, int b)
{
    return (r * 256 * 256) + (g * 256) + b;
}

unsigned int	get_color(char *str, t_data *data)
{
	int				i;
	int				j;
	char			**rgb;

	//fprintf(stderr, "IM HERE ASSAT!\n");
	i = 0;
	j = 0;
	rgb = ft_split(str, ',');
	while (rgb[i])
		i++;
	if (i != 3)
		print_and_exit("Invalid color!");
	while (j < 3)
	{
		if (ft_isdigit(rgb[j][0]) == 0)
			print_and_exit("Invalid color!");
		j++;
	}
	data->color.r = atoi(rgb[0]);
	data->color.g = atoi(rgb[1]);
	data->color.b = atoi(rgb[2]);
	if (data->color.r < 0 || data->color.r > 255 || data->color.g < 0
		|| data->color.g > 255 || data->color.b < 0 || data->color.b > 255)
		print_and_exit("Invalid color!");
	data->color.clr = rgb_to_int(data->color.r, data->color.g, data->color.b);
	return (data->color.clr);
}

char	*get_str(char *str)
{
	char	*string;

	string = NULL;
	if (str[0] == 'N' && str[1] == 'O' && (str[2] == ' ' || str[2] == '\t'))
		string = ft_strdup("NO");
	else if (str[0] == 'S' && str[1] == 'O' && (str[2] == ' ' || str[2] == '\t'))
		string = ft_strdup("SO");
	else if (str[0] == 'W' && str[1] == 'E' && (str[2] == ' ' || str[2] == '\t'))
		string = ft_strdup("WE");
	else if (str[0] == 'E' && str[1] == 'A' && (str[2] == ' ' || str[2] == '\t'))
		string = ft_strdup("EA");
	else if (str[0] == 'F' && (str[1] == ' ' || str[1] == '\t'))
		string = ft_strdup("F");
	else if (str[0] == 'C' && (str[1] == ' ' || str[1] == '\t'))
		string = ft_strdup("C");
	else
		print_and_exit("**** Error occured! Please check again!");
	return (string);
}

void	which_str(char *str, t_data *data)
{
	char	*string;

	string = get_str(str);
	if (ft_strlen(str) > ft_strlen(string) + 1)
		str += ft_strlen(string);
	while (*str && *str == ' ')
		str++;
	if (!ft_strcmp(string, "NO") || !ft_strcmp(string, "SO")
		|| !ft_strcmp(string, "WE") || !ft_strcmp(string, "EA"))
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
	else if (!ft_strcmp(string, "F") || !ft_strcmp(string, "C"))
	{
		if (!ft_strcmp(string, "C"))
			data->main_map.text.the_color.c = get_color(str, data);
		else
			data->main_map.text.the_color.f = get_color(str, data);
	}
	else
		print_and_exit("---- Error occured! Please check again!");
}

void	get_element(char **map, t_data *data)
{
	int		i;
	char	*str;

	i = 0;
	while (map[i] && i < 6)
	{
		str = ft_strtrim(map[i], " ");
		str = ft_strtrim(map[i], "\n");
		//fprintf(stderr, "str = %s\n", str);
		which_str(str, data);
		i++;
	}
}
