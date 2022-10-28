/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 22:44:50 by yagnaou           #+#    #+#             */
/*   Updated: 2022/10/27 20:44:28 by yagnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

char	*trimming(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	j = ft_strlen(str) - 2;
	while (j > 0 && (str[j] == ' ' || str[j] == '\t' || str[i] == '\n'))
		j--;
	return (ft_substr(str, i, j - i + 1));
}

int	check_for_fc(char c, int *count)
{
	if (c == 'F')
		*count += 1;
	return (*count);
}

unsigned int	rgb_to_int(int r, int g, int b)
{
	return ((r * 256 * 256) + (g * 256) + b);
}

unsigned int	get_color(char *str, t_data *data)
{
	int		i;
	int		j;
	char	**rgb;

	i = 0;
	j = -1;
	rgb = ft_split(str, ',');
	while (rgb[i])
		i++;
	if (i != 3)
		print_and_exit("Invalid color!");
	while (++j < 3)
	{
		if (ft_isdigit(rgb[j][0]) == 0)
			print_and_exit("Invalid color!");
	}
	data->color.r = atoi(rgb[0]);
	data->color.g = atoi(rgb[1]);
	data->color.b = atoi(rgb[2]);
	if (data->color.r < 0 || data->color.r > 255 || data->color.g < 0
		|| data->color.g > 255 || data->color.b < 0 || data->color.b > 255)
		print_and_exit("Invalid color!");
	data->color.clr = rgb_to_int(data->color.r, data->color.g, data->color.b);
	free_array(rgb);
	return (data->color.clr);
}

char	*get_str(char *str)
{
	char	*string;
	int		i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	string = NULL;
	if (str[0] == 'N' && str[1] == 'O' && (str[2] == ' ' || str[2] == '\t'))
		string = ft_strdup("NO");
	else if (str[0] == 'S' && str[1] == 'O' && (str[2] == ' '
			|| str[2] == '\t'))
		string = ft_strdup("SO");
	else if (str[0] == 'W' && str[1] == 'E' && (str[2] == ' '
			|| str[2] == '\t'))
		string = ft_strdup("WE");
	else if (str[0] == 'E' && str[1] == 'A' && (str[2] == ' '
			|| str[2] == '\t'))
		string = ft_strdup("EA");
	else if (str[0] == 'F' && (str[1] == ' ' || str[1] == '\t'))
		string = ft_strdup("F");
	else if (str[0] == 'C' && (str[1] == ' ' || str[1] == '\t'))
		string = ft_strdup("C");
	else
		print_and_exit("Error occured! Please check again!");
	return (string);
}
