/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraimi <abraimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 00:21:44 by abraimi           #+#    #+#             */
/*   Updated: 2024/12/19 12:22:40 by abraimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t idx;

	if (!str || !*str)
		return (0);
	idx = 0;
	while (str[idx])
		idx++;
	return (idx);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len;
	size_t	idx;
	size_t	sub;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	idx = 0;
	while (s1[idx])
	{
		str[idx] = s1[idx];
		idx++;
	}
	sub = 0;
	while (s2[sub])
		str[idx++] = s2[sub++];
	str[idx] = '\0';
	return (str);
}
