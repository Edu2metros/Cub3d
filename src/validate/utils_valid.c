/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 00:55:31 by eddos-sa          #+#    #+#             */
/*   Updated: 2024/04/28 00:55:35 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*
	is_extremities_closed

	Checa se as linhas do topo e do final contém
	apenas paredes
*/

int	is_extremities_closed(char *top_line, char *bot_line)
{
	if (is_a_dif_char(top_line, '1') == FALSE || is_a_dif_char(bot_line,
			'1') == FALSE)
		return (FALSE);
	return (TRUE);
}

int	ft_isspace_two(char **map_start, int i, int j)
{
	if (!map_start[i - 1][j] || !map_start[i + 1][j] || !map_start[i][j - 1]
		|| !map_start[i][j + 1])
		return (FALSE);
	if (map_start[i - 1][j] == ' ' || map_start[i + 1][j] == ' '
		|| map_start[i][j - 1] == ' ' || map_start[i][j + 1] == ' ')
		return (FALSE);
	return (TRUE);
}

int	ft_isvalid(char c)
{
	return (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W');
}
