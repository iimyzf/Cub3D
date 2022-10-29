/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:19:13 by yagnaou           #+#    #+#             */
/*   Updated: 2022/10/27 01:22:21 by yagnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hmw(char *str, char del)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (del)
	{
		while (str[i] != '\0')
		{
			if (str[i] != del)
				j++;
			while (str[i] != del && str[i] != '\0')
				i++;
			while (str[i] == del)
				i++;
		}
	}
	else
		j = 0;
	return (j);
}

int	ft_length(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
}

char	**ft_split(char *s, char c)
{
	char	**arr;
	int		n;

	if (!s)
		return (NULL);
	n = 0;
	arr = (char **)malloc(sizeof(char *) * (ft_hmw(s, c) + 1));
	if (!arr)
		return (NULL);
	while (*s && n != 6)
	{
		while (*s == c)
			s++;
		if (*s != c && *s)
		{
			arr[n] = ft_substr(s, 0, ft_length(s, c));
			s = s + ft_length(s, c);
			n++;
		}
	}
	arr[n] = NULL;
	return (arr);
}
