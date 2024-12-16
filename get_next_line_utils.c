/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraimi <abraimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 00:21:44 by abraimi           #+#    #+#             */
/*   Updated: 2024/12/16 23:20:54 by abraimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/_types/_size_t.h>

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

char	*ft_strjoin( char *s1, char *s2)
{
	size_t	len;
	size_t	idx;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	idx = 0;
	while (*s1 && *s1 != '\n')
		str[idx++] = *s1++;
	while (*s2 && *s2 != '\n')
		str[idx++] = *s2++;
	str[idx] = '\0';
	return (str);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	size_t			len;
	size_t			idx;

	len = count * size;
	ptr = (unsigned char *)malloc(len);
	if (ptr)
	{
		idx = 0;
		while (idx < len)
			ptr[idx++] = 0;
	}
	return (ptr);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const unsigned char	*ptr_src;
	unsigned char		*ptr_dst;
	size_t				idx;

	if (src == NULL && dst == NULL)
		return (dst);
	ptr_src = (const unsigned char *)src;
	ptr_dst = (unsigned char *)dst;
	idx = 0;
	while (idx < n)
	{
		ptr_dst[idx] = ptr_src[idx];
		idx++;
	}
	return (ptr_dst);
}

