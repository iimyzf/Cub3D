/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 00:19:42 by yagnaou           #+#    #+#             */
/*   Updated: 2022/10/07 12:48:03 by yagnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	check_file(char *path)
{
	int		i;
	int		j;
	char	*cub;

	i = 0;
	j = 3;
	cub = ".cub";
	if (ft_strlen(path) <= 4)
		return (0);
	while (path[i])
		i++;
	i--;
	while (j >= 0)
	{
		if (cub[j] != path[i])
			return (0);
		i--;
		j--;
	}
	return (1);
}