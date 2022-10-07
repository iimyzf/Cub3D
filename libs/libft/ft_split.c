/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <azabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:32:11 by azabir            #+#    #+#             */
/*   Updated: 2022/10/06 14:35:52 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_strcount(char const *l, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (c)
	{
		while (l[i])
		{
			if (l[i] != c)
				j++;
			while (l[i] != c && l[i] != '\0')
				i++;
			while (l[i] == c)
				i++;
		}
	}
	else
		j = 1;
	return (j);
}

void	ft_mkstr(char **h, char const *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] != c && s[i])
		{
			k++;
			i++;
		}
		while (s[i] == c && c)
			i++;
		h[j] = malloc(sizeof(char) * (k + 1));
		if (!h[j])
			free(h);
		j++;
		k = 0;
	}
}

void	ft_copy(char **h, char const *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] != c && s[i])
		{
			h[k][j] = s[i];
			j++;
			i++;
		}
		h[k][j] = '\0';
		while (s[i] == c && c)
			i++;
		k++;
		j = 0;
	}
	h[k] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**h;
	int		i;
	int		j;

	if (!s || !*s)
	{
		h = malloc(sizeof(char *) * 1);
		if (!h)
			return (NULL);
		*h = NULL;
		return (h);
	}
	i = 0;
	while (s[i] == c)
		i++;
	j = ft_strcount(s, c);
	h = malloc(sizeof(char *) * (j + 1));
	if (!h)
		return (NULL);
	ft_mkstr(h, s + i, c);
	ft_copy(h, s + i, c);
	return (h);
}
