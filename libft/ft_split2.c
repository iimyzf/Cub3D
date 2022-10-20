/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:19:13 by yagnaou           #+#    #+#             */
/*   Updated: 2022/10/14 22:13:00 by yagnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_split2(char *s, char c)
{
	int		n;
	int		i;

	if (!s)
		return (NULL);
	n = 0;
	i = 0;
	while (s[i] && n != 6)
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			n++;
	}
	while (s[i] == c)
			i++;
	return (i);
}