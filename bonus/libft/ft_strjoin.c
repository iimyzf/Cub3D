/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:14:15 by yagnaou           #+#    #+#             */
/*   Updated: 2022/10/27 01:23:09 by yagnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *str, char *buf)
{
	char	*ptr;
	size_t	j;

	if (!str || !buf)
		return (NULL);
	j = ft_strlen(str);
	j += 1;
	ptr = malloc(sizeof(char) * (j + 1));
	if (!ptr)
		return (NULL);
	j = 0;
	while (str[j])
	{
		ptr[j] = str[j];
		j++;
	}
	while (*buf)
		ptr[j++] = *buf++;
	ptr[j] = 0;
	free(str);
	return (ptr);
}
