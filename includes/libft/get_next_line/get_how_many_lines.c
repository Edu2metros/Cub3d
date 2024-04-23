/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_how_many_lines.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:34:49 by eddos-sa          #+#    #+#             */
/*   Updated: 2024/04/23 14:40:09 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	get_how_many_lines(int fd)
{
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		i++;
		free(line);
	}
	if(line)
		free(line);
	return (i);
}
