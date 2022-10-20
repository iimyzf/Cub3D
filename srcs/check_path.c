/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:29:15 by yagnaou           #+#    #+#             */
/*   Updated: 2022/10/07 12:48:20 by yagnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	get_image(char *str, t_data *data)
{
	data->mlx = mlx_init();
	data->img.ptr = mlx_xpm_file_to_image(data->mlx, str, 
		&data->win.hight, &data->win.width);
	if (data->img.ptr == NULL)
		print_and_exit("Path invalid!");
}

unsigned int rgb_to_int(int r, int g, int b)
{
    return (r * 256 * 256) + (g * 256) + b;
}

unsigned int	get_color(char *str, t_color *color)
{
	int				i;
	int				j;
	unsigned int	col;
	char			**rgb;

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
	color->r = atoi(rgb[0]);
	color->g = atoi(rgb[1]);
	color->b = atoi(rgb[2]);
	if (color->r < 0 || color->r > 255 || color->g < 0
		|| color->g > 255 || color->b < 0 || color->b > 255)
		print_and_exit("Invalid color!");
	col = rgb_to_int(color->r, color->g, color->b);
	return (col);
}

char	*get_str(char *str)
{
	int		i;
	char	*string;

	i = 0;
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
		print_and_exit("Error occured! Please check again!");
	return (string);
}

void	which_str(char *str, t_color *color)
{
	// int		i;
	// char	*string;

	// string = get_str(str);
	// if (ft_strlen(str) > ft_strlen(string) + 1)
	// 	str += ft_strlen(string);
	// while (*str && *str == ' ')
	// 	str++;
	// if (!ft_strcmp(string, "NO") || !ft_strcmp(string, "SO")
	// 	|| !ft_strcmp(string, "WE") || !ft_strcmp(string, "EA"))
	// 	//get_image(str, &color);
	// else if (!ft_strcmp(string, "F") || !ft_strcmp(string, "C"))
	// {
	// 	if (!ft_strcmp(string, "C"))
	// 		color->c = get_color(str, color);
	// 	else
	// 		color->f = get_color(str, color);
	// }
}

void	get_element(char *map, t_color *color)
{
	int		i;
	char	*str;

	i = 0;
	while (map[i] && i < 6)
	{
		str = ft_strtrim(map, " ");
		which_str(str, color);
		i++;
	}
}
