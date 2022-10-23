/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 12:43:44 by yagnaou           #+#    #+#             */
/*   Updated: 2022/10/22 21:12:03 by yagnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		print_and_exit("Wrong input!");
	data.fd = open(av[1], O_RDONLY);
	if (data.fd < 0 || !check_file(av[1]))
		print_and_exit("Can't read from file!");
	
	data.main_map.map = read_map(av[1]);
	// data.main_map.map = get_the_map(data.main_map.map);
	
	data.main_map.map = get_the_map(data.main_map.map);
	// if (!check_for_another_map(data.main_map.map))
	// {
	// 	fprintf(stderr, "I'm in!!!\n");
	// 	data.main_map.map = get_the_map(data.main_map.map);
	// }
	map_checking(data.main_map.map, &data);
	// int i = 0;
	// fprintf(stderr, "\n============= Start of the map =============\n\n");
	// while (data.main_map.map[i])
	// {
	// 	fprintf(stderr, "%s", data.main_map.map[i]);
	// 	i++;
	// }
	// fprintf(stderr, "\n============== End of the map ==============\n");
	
	//map_checking(data.main_map.map, &data);
	//data.mlx = mlx_init();
	//data.win->ptr = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HIGHT, "Cub3D");
	//mlx_loop_hook(data.mlx, rendering, &data);
	//mlx_hook(data.win.ptr, 02, 1L<<9, key_hook, &data);
	//mlx_loop(data.mlx);
	return (0);
}