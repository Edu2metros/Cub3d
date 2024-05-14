/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:59:50 by eddos-sa          #+#    #+#             */
/*   Updated: 2024/05/14 11:00:43 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_wallhit(t_vectors **vector, double x, double y)
{
	if (vector[(int)((x))][(int)(y)].type == WALL)
		return (TRUE);
	return (FALSE);
}

int	walk_up(t_cub *cub, double angle, double move_speed)
{
	int	pos_x;
	int	pos_y;

	pos_x = (int)(cub->math->pos_x + PLAYER_RADIUS * cos(angle)
			+ cub->math->dir_x * move_speed);
	pos_y = (int)(cub->math->pos_y + PLAYER_RADIUS * sin(angle)
			+ cub->math->dir_y * move_speed);
	if (is_wallhit(cub->vectors, pos_x, pos_y) == TRUE)
		return (TRUE);
	return (FALSE);
}

int	walk_down(t_cub *cub, double angle, double move_speed)
{
	int	pos_x;
	int	pos_y;

	pos_x = (int)(cub->math->pos_x + PLAYER_RADIUS * cos(angle)
			- cub->math->dir_x * move_speed);
	pos_y = (int)(cub->math->pos_y + PLAYER_RADIUS * sin(angle)
			- cub->math->dir_y * move_speed);
	if (is_wallhit(cub->vectors, pos_x, pos_y) == TRUE)
		return (TRUE);
	return (FALSE);
}
