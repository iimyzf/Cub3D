/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:20:54 by yagnaou           #+#    #+#             */
/*   Updated: 2022/09/25 18:21:02 by yagnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(int i, int s)
{
	char	*p;
	int		j;

	p = (char *)malloc(i * s);
	if (!p)
		return (NULL);
	j = 0;
	while (j < i * s)
	{
		p[j] = 0;
		j++;
	}
	return (p);
}