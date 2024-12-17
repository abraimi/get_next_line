/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraimi <abraimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 04:17:21 by abraimi           #+#    #+#             */
/*   Updated: 2024/12/17 05:27:47 by abraimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	has_nl(char *s)
{
	while (s && *s)
	{
		if (*s == '\n')
			return (1);
	}
	return (0);
}

char	*read_till_nl(int fd, char *buffer, char *vec)
{
	size_t	bytes_r;

	while (1)
	{
		bytes_r = read(fd, buffer, BUFFER_SIZE);
		if (bytes_r == 0)
			break ;
		if (bytes_r == -1)
			return (NULL);
		
	}
}

char	*get_next_line(int fd)
{
	static char		*vec;
	char			*line;
	char			*buffer;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE < 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
}
