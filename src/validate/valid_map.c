/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 00:56:19 by eddos-sa          #+#    #+#             */
/*   Updated: 2024/05/01 14:50:05 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	is_all_land_closed(char **map_start)
{
	int	i;
	int	j;
	int	map_height;

	map_height = find_map_height(map_start);
	if (is_extremities_closed(map_start[0], map_start[map_height]) == FALSE)
		return (FALSE);
	i = 0;
	while (map_start[++i] && i < map_height)
	{
		j = -1;
		while (map_start[i][++j])
		{
			if (ft_isvalid(map_start[i][j]) && ft_isspace_two(map_start, i,
					j) == FALSE)
				return (FALSE);
		}
	}
	return (TRUE);
}

/*
	is_more_than_one_player

	param map_start -> ponto inicial onde iniciam-se os vetores

	o loop while roda por todo o mapa, e utiliza a string
	player_chars para identificar através da funcao strchr
	quantos players o mapa possuí,
		se possuir algum valor diferente de 1 que é o esperado, considera erro.
	(o player pode ser identificado por qualquer um desses caracteres: N, S, E,
		W)
*/

static int	is_more_than_one_player(char **map_start)
{
	int	i;
	int	j;
	int	player_counter;

	i = -1;
	player_counter = 0;
	while (map_start[++i])
	{
		j = -1;
		while (map_start[i][++j])
			if (ft_strchr(PLAYER_CHARS, map_start[i][j]))
				player_counter++;
	}
	if (player_counter != 1)
		return (TRUE);
	return (FALSE);
}

static int	is_valid_characters(char **map_start)
{
	int	i;
	int	j;

	i = -1;
	while (map_start[++i])
	{
		j = -1;
		while (map_start[i][++j])
		{
			if (!ft_strchr(VALID_CHARS, map_start[i][j]))
				return (FALSE);
		}
	}
	return (TRUE);
}

void	validate_map(t_cub *cub, char **map_start)
{
	if (!is_valid_characters(map_start))
		cub->err_flag = TRUE;
	else if (is_more_than_one_player(map_start))
		cub->err_flag = TRUE;
	else if (!is_all_land_closed(map_start))
		cub->err_flag = TRUE;
}
