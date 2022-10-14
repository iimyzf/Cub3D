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

int	main(int arv, char **arc)
{
	t_data	data;

	if (arv != 2)
		exit(1);
	data.fd = open (arc[1], O_RDONLY);
	if (data.fd <= 0)
		exit(2);
	map_check(&data);
	scean_init(&data);
	data.mlx = mlx_init();
	data.win.ptr = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HIGHT, "Cub3D");
	//mlx_loop_hook(data.mlx, rendering, &data);
	rendering(&data);
	mlx_hook(data.win.ptr, 02, 1L<<9, key_hook, &data);
	mlx_loop(data.mlx);
}
