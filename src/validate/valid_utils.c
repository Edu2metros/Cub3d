/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 00:56:48 by eddos-sa          #+#    #+#             */
/*   Updated: 2024/04/29 16:35:22 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	**fill_info(void)
{
	char	**info;

	info = (char **)ft_safe_malloc(sizeof(char *) * 7);
	info[0] = ft_strdup("NO ");
	info[1] = ft_strdup("SO ");
	info[2] = ft_strdup("EA ");
	info[3] = ft_strdup("WE ");
	info[4] = ft_strdup("C ");
	info[5] = ft_strdup("F ");
	info[6] = NULL;
	return (info);
}

int	find_first_char(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isalnum(str[i]) == 1)
			return (i);
		else if (str[i] == '\t' || str[i] == '\f' || str[i] == '\f')
			return (-1);
		i++;
	}
	return (-1);
}

/*
	find_map_height

	seu retorno é + 1 por conta que
	a última linha não contém '\n'
*/

int	map_adjust(char **map_start, int line_counter)
{
	while (!map_start[line_counter])
		line_counter--;
	return (line_counter);
}

int	find_map_height(char **map_start)
{
	int	i;
	int	line_counter;

	i = -1;
	line_counter = 0;
	while (map_start[++i])
	{
		if (ft_strchr(map_start[i], '\n'))
			line_counter++;
	}
	line_counter = map_adjust(map_start, line_counter);
	return (line_counter);
}

int	is_a_dif_char(char *s, char c)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] != c && s[i] != '\n' && s[i] != ' ')
			return (FALSE);
	}
	return (TRUE);
}
