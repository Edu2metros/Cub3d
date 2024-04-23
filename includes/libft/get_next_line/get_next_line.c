/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 11:52:06 by eddos-sa          #+#    #+#             */
/*   Updated: 2024/04/18 16:57:25 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000
#endif

static char	*get_next(char *newline)
{
	char	*str;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!newline || *newline == '\0')
	{
		free(newline);
		return (NULL);
	}
	while (newline[i] && newline[i] != '\n')
		i++;
	str = (char *)ft_calloc(sizeof(char), (ft_strlen(newline) - i + 1));
	if (!str)
		return (NULL);
	if (newline[i] == '\n')
		i++;
	else
		newline[0] = '\0';
	while (newline[i] && newline[i] != '\0')
		str[j++] = newline[i++];
	free(newline);
	return (str);
}

static char	*get_line(char *newline)
{
	int		i;
	char	*s;

	if (*newline == '\0')
		return (NULL);
	i = 0;
	while (newline[i] && newline[i] != '\n')
		i++;
	s = (char *)ft_calloc(sizeof(char), (i + 2));
	if (!s)
		return (NULL);
	i = 0;
	while (newline[i] && newline[i] != '\n')
	{
		s[i] = newline[i];
		i++;
	}
	if (newline[i] == '\n')
	{
		s[i] = newline[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

static char	*get_new_line(int fd, char *newline)
{
	int		line_read;
	char	*buffer;

	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	line_read = 1;
	while (!ft_strchr(newline, '\n') && line_read != 0)
	{
		line_read = read(fd, buffer, BUFFER_SIZE);
		if (line_read == -1)
		{
			free(buffer);
			free(newline);
			return (NULL);
		}
		buffer[line_read] = '\0';
		newline = ft_strjoin(newline, buffer);
	}
	free(buffer);
	return (newline);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*newline;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	newline = get_new_line(fd, newline);
	if (!newline)
		return (NULL);
	line = get_line(newline);
	newline = get_next(newline);
	return (line);
}
