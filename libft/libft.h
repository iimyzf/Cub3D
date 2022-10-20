/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:14:33 by yagnaou           #+#    #+#             */
/*   Updated: 2022/10/19 10:57:32 by yagnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# define MAX_INT 2147483647
# define MAX_INT_P1 2147483648

int		ft_strlen(char *str);
int		ft_isalnum(int c);
int		ft_isdigit(int c);
int		ft_atoi(char *str);
int		ft_strcmp(char *str1, char *str2);
char	*ft_strjoin(char *str, char *buf);
void	*ft_calloc(int i, int s);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strdup(char *src);
char	*ft_strtrim(char *s1, char *set);
char	**ft_split(char *s, char c);
void	ft_bzero(void *s, size_t n);

#endif