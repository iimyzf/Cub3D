/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:43:17 by yagnaou           #+#    #+#             */
/*   Updated: 2022/09/28 18:44:20 by yagnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char	*src)
{
	int		i;
	int		j;
	char	*dst;

	i = 0;
	j = 0;
	while (src[i] != '\0')
		i++;
	dst = (char *) malloc (sizeof(char) * (i + 1));
	if (!dst)
		return (NULL);
	while (j < i)
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (dst);
}