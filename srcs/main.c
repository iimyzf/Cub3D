/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <azabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:30:39 by azabir            #+#    #+#             */
/*   Updated: 2022/10/07 10:58:05 by azabir           ###   ########.fr       */
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
	data.main_map.map = get_the_map(data.main_map.map);
	map_checking(data.main_map.map, &data);
	int	i = 0;
	while (data.main_map.map && data.main_map.map[i])
	{
		if(data.main_map.x_len < ft_strlen(data.main_map.map[i]))
			data.main_map.x_len = ft_strlen(data.main_map.map[i]);
		i++;
	}
	data.main_map.y_len = i;
	data.mlx = mlx_init();
	data.win.ptr = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HIGHT, "Cub3D");
	scean_init(&data);
	//mlx_loop_hook(data.mlx, rendering, &data);
	rendering(&data);
	write (2, "here\n", 5);
	mlx_hook(data.win.ptr, 02, 1L<<9, key_hook, &data);
	mlx_loop(data.mlx);
}


/*

TO DO:

fix player collisions
merge map parcing
norm the code
optimize RAM
handle multiple keys press
Add side moves

DOING:
optimize CPU using
set walls oriantations
 
DONE:


*/