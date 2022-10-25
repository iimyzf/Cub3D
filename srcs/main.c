/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:30:39 by azabir            #+#    #+#             */
/*   Updated: 2022/10/23 00:04:07 by yagnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		print_and_exit("Wrong input!");
	data.mlx = mlx_init();
	data.fd = open(av[1], O_RDONLY);
	if (data.fd < 0 || !check_file(av[1]))
		print_and_exit("Can't read from file!");
	data.main_map.map = read_map(av[1]);
	get_element(data.main_map.map, &data);
	data.main_map.map = get_the_map(data.main_map.map);
	map_checking(data.main_map.map, &data);
	data.win.ptr = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HIGHT, "Cub3D");
	scean_init(&data);
	mlx_hook(data.win.ptr, 02, 0, key_hook, &data);
	mlx_hook(data.win.ptr, 17, 0, ft_exit, &data);
	mlx_loop_hook(data.mlx, rendering, &data);
	mlx_loop(data.mlx);
}
