/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraimi <abraimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 04:17:21 by abraimi           #+#    #+#             */
/*   Updated: 2024/12/19 12:25:20 by abraimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	has_nl(char *s)
{
	while (s && *s)
	{
		if (*s++ == '\n')
			return (1);
	}
	return (0);
}

char	*read_till_nl(int fd, char *buffer, char *vec)
{
	int	bytes_r;
	char *tmp;

	while ((bytes_r = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_r] = '\0';
		if (!vec)
		{
			vec = (char *)malloc(1);
			if (!vec)
				return (NULL);
			vec[0] = '\0';
		}
		tmp = vec;
		vec = ft_strjoin(vec, buffer);
		free(tmp);
		if (!vec)
			break ;
		if (has_nl(buffer))
			break ;
	}
	if (bytes_r == -1)
		return (free(vec), NULL);
	return (vec);
}

char	*line_pull(char *vec)
{
	char	*line;
	size_t	idx;
	size_t	sub;

	if (!vec || !*vec)
		return (NULL);
	idx = 0;
	while (vec[idx] && vec[idx] != '\n')
		idx++;
	if (vec[idx] == '\n')
		line = (char *)malloc(sizeof(char) * (idx + 2));
	else
		line = (char *)malloc(sizeof(char) * (idx + 1));
	if (!line)
		return (NULL);
	idx = 0;
	sub = 0;
	while (vec[idx] && vec[idx] != '\n')
		line[sub++] = vec[idx++];
	if (vec[idx] == '\n')
		line[sub++] = '\n';
	line[sub] = '\0';
	return (line);
}


char	*line_push(char *vec)
{
	char	*new_vec;
	size_t	idx;
	size_t	sub;
	size_t	len;

	if (!vec)
		return (NULL);
	idx = 0;
	while (vec[idx] && vec[idx] != '\n')
		idx++;
	if (vec[idx] == '\0')
		return (free(vec), NULL);
	len = 0;
	while (vec[idx + len])
		len++;
	new_vec = (char *)malloc(len + 1);
	if (!new_vec)
		return (free(vec), NULL);
	idx++;
	sub = 0;
	while (vec[idx])
		new_vec[sub++] = vec[idx++];
	new_vec[sub] = '\0';
	return (free(vec), new_vec);
}


char	*get_next_line(int fd)
{
	static char		*vec[1024];
	char			*line;
	char			*buffer;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(vec[fd]), vec[fd] = NULL, NULL);
	vec[fd] = read_till_nl(fd, buffer, vec[fd]);
	if (!vec[fd])
		free(vec[fd]);
	free(buffer);
	if (!vec[fd])
		return ( NULL);
	line = line_pull(vec[fd]);
	if (!line)
		return (free(vec[fd]), vec[fd] = NULL, NULL);
	vec[fd] = line_push(vec[fd]);
	return (line);
}
