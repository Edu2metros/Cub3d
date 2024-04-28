/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_how_many_lines.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:34:49 by eddos-sa          #+#    #+#             */
/*   Updated: 2024/04/28 01:08:17 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	get_how_many_lines(int fd)
{
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		i++;
		free(line);
	}
	if (line)
		free(line);
	return (i);
}
