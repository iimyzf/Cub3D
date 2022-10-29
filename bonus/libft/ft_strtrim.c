/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:34:11 by yagnaou           #+#    #+#             */
/*   Updated: 2022/10/04 10:35:55 by yagnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_beg(char *s1, char *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0' && set[j] != '\0')
	{
		if (s1[i] == set[j])
		{
			i++;
			j = -1;
		}
		j++;
	}
	return (i);
}

int	check_end(char *s1, char *set)
{
	size_t	j;
	size_t	s1len;

	j = 0;
	s1len = ft_strlen(s1) - 1;
	while (s1len > 0 && set[j] != '\0')
	{
		if (s1[s1len] == set[j])
		{
			s1len--;
			j = -1;
		}
		j++;
	}
	return (s1len);
}

char	*ft_strtrim(char *s1, char *set)
{
	int		beg;
	int		k;
	char	*trimmed;
	int		end;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	k = 0;
	beg = check_beg(s1, set);
	end = check_end(s1, set);
	if (beg > end)
		return (ft_strdup(""));
	trimmed = (char *) malloc ((end - beg + 2) * sizeof(char));
	if (!trimmed)
		return (NULL);
	while (beg <= end && s1 != '\0')
		trimmed[k++] = s1[beg++];
	trimmed[k] = '\0';
	return (trimmed);
}
